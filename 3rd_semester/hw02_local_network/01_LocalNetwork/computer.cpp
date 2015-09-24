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

QChar Computer::getOperatingSystem()
{
	return operatingSystem;
}

bool Computer::isInfected()
{
	return infected;
}


