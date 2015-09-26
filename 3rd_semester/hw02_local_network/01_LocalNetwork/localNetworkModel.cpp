#include "localNetworkModel.h"

LocalNetworkModel::LocalNetworkModel() : model(new Network("input.txt"))
{
}

void LocalNetworkModel::nextTurn()
{
	model->spreadInfection();
	model->printStatus();
}

