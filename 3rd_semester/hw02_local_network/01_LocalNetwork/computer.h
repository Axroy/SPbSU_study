#pragma once

#include <QString>

class Computer
{
public:
	Computer();
	Computer(const QString &operatingSystem);
	void setOperatingSystem(const QString &system);
	void setInfectedStatus(bool status);

private:
	bool isInfected;
	QString operatingSystem;

};

