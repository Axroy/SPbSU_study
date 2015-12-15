#include "networkClient.h"

NetworkClient::NetworkClient(QLabel *statusLabel, QComboBox *hostCombo, QLineEdit *portLineEdit)
{
	this->statusLabel = statusLabel;
	this->hostCombo = hostCombo;
	this->portLineEdit = portLineEdit;

	sessionOpened();
	connect(tcpSocket, SIGNAL(connected()), this, SLOT(connectionEstablished()));
	connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(readMessage()));
	connect(tcpSocket, SIGNAL(disconnected()), this, SLOT(lostConnection()));
}

void NetworkClient::setupConnection()
{
	blockSize = 0;
	tcpSocket->abort();
	tcpSocket->connectToHost(hostCombo->currentText(), portLineEdit->text().toInt());
}

bool NetworkClient::isServer()
{
	return false;
}

void NetworkClient::sessionOpened()
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

void NetworkClient::connectionEstablished()
{
	statusLabel->setText("Connected");
	emit connected();
}

