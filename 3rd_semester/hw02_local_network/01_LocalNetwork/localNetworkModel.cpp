#include "localNetworkModel.h"

LocalNetworkModel::LocalNetworkModel() : model(new Network("input.txt")), turn(0)
{
}

LocalNetworkModel::LocalNetworkModel(const QString &fileName) : model(new Network(fileName)), turn(0)
{
}

LocalNetworkModel::~LocalNetworkModel()
{
	delete model;
}

void LocalNetworkModel::nextTurn()
{
	model->spreadInfection();	
	std::cout << "\n\n" << "Turn: " << turn << "\n";
	model->printStatus();
}

