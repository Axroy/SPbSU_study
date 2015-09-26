#pragma once

#include <QString>

class Computer
{
public:
	Computer();
	void setOperatingSystem(const QChar &system);
	void setInfectedStatus(bool status);
	void setRecentlyInfectedStatus(bool status);
	/**
	 * @brief Tries to infect this computer
	 * @return true if successfully infected, false if infection failed or already infected
	 */
	bool tryToInfect();
	bool isInfected();
	bool isRecentlyInfected();
	QChar getOperatingSystem();

private:
	bool infected;
	bool recentlyInfected;
	QChar operatingSystem;
};

