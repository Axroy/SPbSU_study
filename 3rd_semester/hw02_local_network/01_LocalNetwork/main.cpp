#include <QCoreApplication>
#include <iostream>

#include "network.h"

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	Network *test = new Network("input.txt");
	test->printStatus();

	return a.exec();
}
