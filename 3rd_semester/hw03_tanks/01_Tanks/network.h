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
	virtual void setupConnection() = 0;
	/// Clears all received data
	void clearBuffer();
	void sendMessage(Message message);
	virtual bool isServer() = 0;


signals:
	void connected();
	void disconnected();
	void messageReceived(Message message);

protected slots:
	virtual void sessionOpened() = 0;
	virtual void connectionEstablished() = 0;
	void readMessage();
	void lostConnection();

protected:
	QTcpSocket *tcpSocket;
	QNetworkSession *networkSession;
	QString ipAddress;
	qint16 blockSize;
	QLabel *statusLabel;
	QComboBox *hostCombo;
	QLineEdit *portLineEdit;
};

