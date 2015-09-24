#pragma once

#include <QFile>
#include <QTextStream>
#include <iostream>

#include "computer.h"

class Network
{
public:
	Network();
	/**
	 * @brief Creates a network using data file in following format:
	 * number of computers
	 * <empty line>
	 * operating system and infection status for each one (n lines)
	 * (example: "W 0" = Windows, non-infected)
	 * <empty line>
	 * matrix with connections in the network (n * n, 1 or 0 in each cell)
	 *
	 * @param fileName - name of the input file
	 */
	Network(const QString &fileName);

	void printStatus();

private:
	int size;
	int **connections;
	Computer *computers;
};
