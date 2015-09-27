#pragma once

#include "network.h"

///Class for simulating local network infection
class LocalNetworkModel
{
public:
	LocalNetworkModel();
	/**
	 * @brief LocalNetworkModel constructor
	 * @param fileName - name of data file in following format:
	 * <file beginning>
	 * number of computers
	 * <empty line>
	 * operating system and infection status for each one (n lines)
	 * (example: "W 0" = Windows, non-infected)
	 * <empty line>
	 * matrix with connections in the network (n * n, 1 or 0 in each cell)
	 * <end of file>
	 */
	LocalNetworkModel(const QString &fileName);
	~LocalNetworkModel();
	/**
	 * @brief Simulates turn-based infection of local network.
	 * Ends when all parts of network are infected.
	 */
	void simulate();

private:
	void nextTurn();

	Network *model;
	int turn;
};

