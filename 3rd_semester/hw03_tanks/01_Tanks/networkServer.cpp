#include "networkServer.h"

NetworkServer::NetworkServer(QLabel *statusLabel, QComboBox *hostCombo, QLineEdit *portLineEdit)
{
	this->statusLabel = statusLabel;
	this->hostCombo = hostCombo;
	this->portLineEdit = portLineEdit;

	sessionOpened();
	connect(tcpServer, SIGNAL(newConnection()), this, SLOT(connectionEstablished()));
}

void NetworkServer::setupConnection()
{

}

bool NetworkServer::isServer()
{
	return true;
}

void NetworkServer::sessionOpened()
{
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

void NetworkServer::connectionEstablished()
{
	statusLabel->setText("Connected");
	blockSize = 0;
	tcpSocket = tcpServer->nextPendingConnection();
	connect(tcpSocket, SIGNAL(disconnected()), tcpSocket, SLOT(deleteLater()));
	connect(tcpSocket, SIGNAL(disconnected()), this, SLOT(lostConnection()));
	connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(readMessage()));

	emit connected();
}

