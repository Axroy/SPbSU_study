#include <QCoreApplication>
#include <iostream>

#include "localNetworkModel.h"

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	std::cout << "Enter input file name: ";
	QTextStream input(stdin);
	QString fileName = input.readLine();

	LocalNetworkModel *model = new LocalNetworkModel(fileName);
	for (int i = 0; i < 10; i++)
		model->nextTurn();

	delete model;

	return a.exec();
}
