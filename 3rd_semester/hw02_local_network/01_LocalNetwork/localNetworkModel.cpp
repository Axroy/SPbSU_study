#include "localNetworkModel.h"

LocalNetworkModel::LocalNetworkModel() : model(new Network("input.txt")), turn(0)
{
}

void LocalNetworkModel::nextTurn()
{
	model->spreadInfection();	
	std::cout << "\n\n" << "Turn: " << turn << "\n";
	model->printStatus();
}

