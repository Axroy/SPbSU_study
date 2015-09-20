#include "computer.h"

Computer::Computer() : isInfected(false), operatingSystem("Windows")
{
}

Computer::Computer(const QString &operatingSystem) : operatingSystem(operatingSystem)
{
}

void Computer::setOperatingSystem(const QString &system)
{
	operatingSystem = system;
}

void Computer::setInfectedStatus(bool status)
{
	isInfected = status;
}


