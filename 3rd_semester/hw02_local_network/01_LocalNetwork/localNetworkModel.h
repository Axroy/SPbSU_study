#pragma once

#include "network.h"

class LocalNetworkModel
{
public:
	LocalNetworkModel();
	void nextTurn();

private:
	Network *model;
};

