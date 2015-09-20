#pragma once

#include <QFile>
#include <QTextStream>

#include "computer.h"

class Network
{
public:
	Network();
	Network(const QString &fileName);

private:
	int size;
	int **connections;
	Computer *computers;
};
