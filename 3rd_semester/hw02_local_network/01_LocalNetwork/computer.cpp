#include <QTime>
#include "computer.h"

Computer::Computer() : infected(false), recentlyInfected(false), operatingSystem('W')
{
}

void Computer::setOperatingSystem(const QChar &system)
{
	operatingSystem = system;
}

void Computer::setInfectedStatus(bool status)
{
	infected = status;
}

void Computer::setRecentlyInfectedStatus(bool status)
{
	recentlyInfected = status;
}

bool Computer::tryToInfect()
{
	if (infected)
		return false;

	qsrand(QTime::currentTime().msec());
	int infectionChance = 0;
	switch (operatingSystem.toLatin1())
	{
		case 'W':
			infectionChance = 25;
			break;
		case 'L':
			infectionChance = 5;
			break;
		case 'M':
			infectionChance = 20;
			break;
	}
	if (qrand() % 100 <= infectionChance)
		infected = true;
	return infected;
}

QChar Computer::getOperatingSystem()
{
	return operatingSystem;
}

bool Computer::isInfected()
{
	return infected;
}

bool Computer::isRecentlyInfected()
{
	return recentlyInfected;
}


