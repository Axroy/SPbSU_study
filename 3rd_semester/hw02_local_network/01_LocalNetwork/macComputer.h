#pragma once

#include "computer.h"

class MacComputer : public Computer
{
public:
	MacComputer();
	QChar getOperatingSystem();
};
