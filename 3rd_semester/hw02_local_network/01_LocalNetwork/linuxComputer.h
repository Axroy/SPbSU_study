#pragma once

#include "computer.h"

class LinuxComputer : public Computer
{
public:
	LinuxComputer();
	QChar getOperatingSystem();
};
