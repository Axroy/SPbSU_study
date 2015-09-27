#include <QCoreApplication>
#include <iostream>

#include "localNetworkModel.h"

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	std::cout << "Enter input file name: ";
	QTextStream input(stdin);
	QString fileName = input.readLine();

	if (!QFile(fileName).exists())
	{
		std::cout << "The file doesn't exist!";
		return a.exec();
	}

	LocalNetworkModel *model = new LocalNetworkModel(fileName);
	model->simulate();
	delete model;

	return a.exec();
}
