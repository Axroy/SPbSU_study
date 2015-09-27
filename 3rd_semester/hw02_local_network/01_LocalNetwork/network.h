#pragma once

#include <QFile>
#include <QTextStream>
#include <iostream>

#include "computer.h"

///Class representing a local network: some computers with some connections between them
class Network
{
public:
	/**
	 * @brief Creates a network using data file in following format:
	 *
	 * <file beginning>
	 * number of computers
	 * <empty line>
	 * operating system and infection status for each one (n lines)
	 * (example: "W 0" = Windows, non-infected)
	 * <empty line>
	 * matrix with connections in the network (n * n, 1 or 0 in each cell)
	 * <end of file>
	 *
	 * @param fileName - name of the input file
	 */
	Network(const QString &fileName);
	~Network();

	/**
	 * @brief Prints to console computers wiith their operating systems and infection statuses
	 */
	void printStatus();
	/**
	 * @brief Tries to infect computers connected with infected ones
	 */
	void spreadInfection();
	/**
	 * @brief allInfected
	 * @return true if all computers in the network are infected, false otherwise
	 */
	bool allInfected();

private:
	int size;
	int **connections;
	Computer *computers;
};
