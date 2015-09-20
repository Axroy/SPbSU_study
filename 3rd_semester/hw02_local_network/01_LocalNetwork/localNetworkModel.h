#pragma once

#include "computer.h"

class LocalNetworkModel
{
public:
	LocalNetworkModel();
	void nextTurn();

private:
	Computer **connectionsMatrix;
};

