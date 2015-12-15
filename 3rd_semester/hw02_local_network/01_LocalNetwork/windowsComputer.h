#pragma once

#include "computer.h"

class WindowsComputer : public Computer
{
public:
	WindowsComputer();
	QChar getOperatingSystem();
};

