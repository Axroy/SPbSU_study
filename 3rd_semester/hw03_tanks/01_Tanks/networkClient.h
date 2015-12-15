#pragma once

#include "network.h"

class NetworkClient : public Network
{
public:
	/// The label, the comboBox and the lineEdit are used to show connection status,
	/// available IPs and available ports correspondingly
	NetworkClient(QLabel *statusLabel, QComboBox *hostCombo, QLineEdit *portLineEdit);
	void setupConnection();
	bool isServer();

private slots:
	void sessionOpened();
	void connectionEstablished();
};

