#include <QCoreApplication>
#include <iostream>

#include "localNetworkModel.h"

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	LocalNetworkModel *model = new LocalNetworkModel();
	for (int i = 0; i < 10; i++)
		model->nextTurn();

	return a.exec();
}
