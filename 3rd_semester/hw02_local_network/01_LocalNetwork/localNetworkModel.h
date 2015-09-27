#pragma once

#include "network.h"

class LocalNetworkModel
{
public:
	LocalNetworkModel();
	LocalNetworkModel(const QString &fileName);
	~LocalNetworkModel();
	void simulate();

private:
	void nextTurn();

	Network *model;
	int turn;
};

