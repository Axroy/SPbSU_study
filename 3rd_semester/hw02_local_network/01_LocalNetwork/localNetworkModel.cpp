#include "localNetworkModel.h"

LocalNetworkModel::LocalNetworkModel(const QString &fileName) : model(new Network(fileName)), turn(0)
{
}

LocalNetworkModel::~LocalNetworkModel()
{
	delete model;
}

void LocalNetworkModel::simulate()
{
	while (!model->allInfected())
		nextTurn();
	std::cout << "\n\nAll computers are infected!!!";
}

void LocalNetworkModel::nextTurn()
{
	model->spreadInfection();	
	std::cout << "\n\n" << "Turn: " << turn << "\n";
	turn++;
	model->printStatus();
}

