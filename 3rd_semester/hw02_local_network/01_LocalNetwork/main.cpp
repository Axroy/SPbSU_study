#include <QCoreApplication>
#include <iostream>

#include "localNetworkModel.h"
#include "networkTests.h"

int main(int argc, char *argv[])
{
	NetworkTests tests;
	QTest::qExec(&tests);


	QCoreApplication a(argc, argv);

	std::cout << "\n\nEnter input file name: ";
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
