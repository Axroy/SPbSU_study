#include "network.h"

Network::Network(NetworkType type, QLabel *statusLabel, QComboBox *hostCombo,
				 QLineEdit *portLineEdit) :
	type(type),
	statusLabel(statusLabel),
	hostCombo(hostCombo),
	portLineEdit(portLineEdit)
{

	sessionOpened();

	if (type == server)
	{
		connect(tcpServer, SIGNAL(newConnection()), this, SLOT(connectedAsServer()));
		return;
	}

	if (type == client)
	{
		connect(tcpSocket, SIGNAL(connected()), this, SLOT(connectedAsClient()));
		connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(readMessage()));
		connect(tcpSocket, SIGNAL(disconnected()), this, SLOT(lostConnection()));
		return;
	}
}

void Network::setupConnection()
{
	if (type == server)
		return;

	blockSize = 0;
	tcpSocket->abort();
	tcpSocket->connectToHost(hostCombo->currentText(), portLineEdit->text().toInt());
}

void Network::clearBuffer()
{
	tcpSocket->readAll();
}

void Network::sendMessage(Message message)
{
	QByteArray block;
	QDataStream out(&block, QIODevice::WriteOnly);
	out.setVersion(QDataStream::Qt_4_0);
	out << (quint16)0;
	out << message;
	out.device()->seek(0);
	out << (quint16)(block.size() - sizeof(quint16));

	tcpSocket->write(block);
}

bool Network::isServer()
{
	return type == server;
}

void Network::sessionOpened()
{
	if (type == client)
	{
		tcpSocket = new QTcpSocket(this);

		// find out name of this machine
		QString name = QHostInfo::localHostName();
		if (!name.isEmpty()) {
			hostCombo->addItem(name);
			QString domain = QHostInfo::localDomainName();
			if (!domain.isEmpty())
				hostCombo->addItem(name + QChar('.') + domain);
		}
		if (name != QString("localhost"))
			hostCombo->addItem(QString("localhost"));
		// find out IP addresses of this machine
		QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
		// add non-localhost addresses
		for (int i = 0; i < ipAddressesList.size(); ++i) {
			if (!ipAddressesList.at(i).isLoopback())
				hostCombo->addItem(ipAddressesList.at(i).toString());
		}
		// add localhost addresses
		for (int i = 0; i < ipAddressesList.size(); ++i) {
			if (ipAddressesList.at(i).isLoopback())
				hostCombo->addItem(ipAddressesList.at(i).toString());
		}

		portLineEdit->setValidator(new QIntValidator(1, 65535, this));

		statusLabel->setText("Run the server");

		return;
	}

	tcpServer = new QTcpServer(this);
	if (!tcpServer->listen())
	{
		return;
	}

	QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
	// use the first non-localhost IPv4 address
	for (int i = 0; i < ipAddressesList.size(); ++i)
	{
		if (ipAddressesList.at(i) != QHostAddress::LocalHost &&
			ipAddressesList.at(i).toIPv4Address())
		{
			ipAddress = ipAddressesList.at(i).toString();
			break;
		}
	}
	// if we did not find one, use IPv4 localhost
	if (ipAddress.isEmpty())
		ipAddress = QHostAddress(QHostAddress::LocalHost).toString();

	statusLabel->setText(tr("The server is running on\n\nIP: %1\nport: %2\n\n"
							"Run the client now.")
						 .arg(ipAddress).arg(tcpServer->serverPort()));
}

void Network::connectedAsServer()
{
	statusLabel->setText("Connected");
	blockSize = 0;
	tcpSocket = tcpServer->nextPendingConnection();
	connect(tcpSocket, SIGNAL(disconnected()), tcpSocket, SLOT(deleteLater()));
	connect(tcpSocket, SIGNAL(disconnected()), this, SLOT(lostConnection()));
	connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(readMessage()));

	emit connected();
}

void Network::connectedAsClient()
{
	statusLabel->setText("Connected");
	emit connected();
}

void Network::readMessage()
{
	QDataStream in(tcpSocket);
	in.setVersion(QDataStream::Qt_4_0);

	if (blockSize == 0)
	{
		if (tcpSocket->bytesAvailable() < (int)sizeof(quint16))
			return;

		in >> blockSize;
	}

	if (tcpSocket->bytesAvailable() < blockSize)
		return;

	int message;
	in >> message;
	blockSize = 0;

	emit messageReceived((Message)message);
}

void Network::lostConnection()
{
	statusLabel->setText("Disconnected");
	emit disconnected();
}

