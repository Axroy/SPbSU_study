#pragma once

#include <QObject>
#include <QtNetwork>
#include <QtWidgets>
#include <QLabel>

#include "networkEnums.h"

/// Class used to do all the network stuff
class Network : public QObject
{
	Q_OBJECT

public:
	/// The type - client or server
	/// The label, the comboBox and the lineEdit are used to show connection status,
	/// available IPs and available ports correspondingly
	Network(NetworkType type, QLabel *statusLabel, QComboBox *hostCombo, QLineEdit *portLineEdit);
	void setupConnection();
	/// Clears all received data
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

