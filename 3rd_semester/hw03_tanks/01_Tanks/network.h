#pragma once

#include <QObject>
#include <QtNetwork>
#include <QtWidgets>
#include <QLabel>

#include "networkEnums.h"

class Network : public QObject
{
	Q_OBJECT

public:
	Network(NetworkType type, QLabel *statusLabel, QComboBox *hostCombo,
			QLineEdit *portLineEdit);
	void setupConnection();
	void clearBuffer();
	void sendMessage(Message message);
	bool isServer();


signals:
	void connected();
	void disconnected();
	void messageReceived(Message message);

private slots:
	void sessionOpened();
	void connectedAsServer();
	void connectedAsClient();
	void readMessage();
	void lostConnection();

private:
	QTcpServer *tcpServer;
	QTcpSocket *tcpSocket;
	QNetworkSession *networkSession;
	QString ipAddress;
	qint16 blockSize;
	NetworkType type;
	QLabel *statusLabel;
	QComboBox *hostCombo;
	QLineEdit *portLineEdit;
};

