#include <QTime>
#include "computer.h"

Computer::Computer() : infected(false), operatingSystem('W')
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

void Computer::tryToInfect()
{
	if (infected)
		return;

	qsrand(QTime::currentTime().msec());
	float infectionChance = 0;
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
	if (qrand() % 100 < infectionChance)
		infected = true;
}

QChar Computer::getOperatingSystem()
{
	return operatingSystem;
}

bool Computer::isInfected()
{
	return infected;
}


