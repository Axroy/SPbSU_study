#include <QTime>
#include "computer.h"

Computer::Computer() : infected(false), recentlyInfected(false)
{
}

void Computer::setInfectedStatus(bool status)
{
	infected = status;
}

void Computer::setRecentlyInfectedStatus(bool status)
{
	recentlyInfected = status;
}

bool Computer::tryToInfect(bool guaranteed)
{
	if (infected)
		return false;

	if (guaranteed)
	{
		infected = true;
		return infected;
	}

	qsrand(QTime::currentTime().msec());
	if (qrand() % 100 <= infectionChance)
		infected = true;
	return infected;
}

bool Computer::isInfected()
{
	return infected;
}

bool Computer::isRecentlyInfected()
{
	return recentlyInfected;
}


