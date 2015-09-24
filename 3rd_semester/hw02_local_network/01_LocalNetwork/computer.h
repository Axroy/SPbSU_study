#pragma once

#include <QString>

class Computer
{
public:
	Computer();
	void setOperatingSystem(const QChar &system);
	void setInfectedStatus(bool status);
	bool isInfected();
	QChar getOperatingSystem();

private:
	bool infected;
	QChar operatingSystem;

};

