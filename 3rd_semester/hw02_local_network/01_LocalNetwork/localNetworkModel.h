#pragma once

#include "network.h"

class LocalNetworkModel
{
public:
	LocalNetworkModel();
	LocalNetworkModel(const QString &fileName);
	~LocalNetworkModel();
	void nextTurn();

private:
	Network *model;
	int turn;
};

