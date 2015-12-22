#pragma once

#include "network.h"

class NetworkServer : public Network
{
public slots:
	void setupConnection();

public:
	/// The label, the comboBox and the lineEdit are used to show connection status,
	/// available IPs and available ports correspondingly
	NetworkServer(QLabel *statusLabel, QComboBox *hostCombo, QLineEdit *portLineEdit);
	bool isServer();

private slots:
	void sessionOpened();
	void connectionEstablished();

private:
	QTcpServer *tcpServer;
};

