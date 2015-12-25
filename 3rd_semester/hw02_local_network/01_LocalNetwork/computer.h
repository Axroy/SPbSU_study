#pragma once

#include <QString>

///Class representing a computer in the local network.
class Computer
{
public:
	/**
	 * @brief Default computer is non-infected
	 */
	Computer();
	/**
	 * @brief Makes the computer infected or not infected
	 * @param status - true for infection, false for cleaning one
	 */
	void setInfectedStatus(bool status);
	/**
	 * @brief Makes infection of the computer recent or not recent
	 * @param status - true for recent infection, false for not recent
	 */
	void setRecentlyInfectedStatus(bool status);
	/**
	 * @brief Tries to infect this computer
	 * (chance of success depends on operating system)
	 * @return true if successfully infected, false if infection failed or already infected
	 */
	bool tryToInfect(bool guaranteed = false);
	/**
	 * @brief Checks whether the computer is infected
	 * @return true if infected, false if not
	 */
	bool isInfected();
	/**
	 * @brief  Checks whether the computer is recently infected
	 * @return true if recently, false if not
	 */
	bool isRecentlyInfected();
	/**
	 * @brief getOperatingSystem
	 * @return operating system of the computer
	 */
	virtual QChar getOperatingSystem() = 0;

protected:
	bool infected;
	bool recentlyInfected;
	int infectionChance;
};

