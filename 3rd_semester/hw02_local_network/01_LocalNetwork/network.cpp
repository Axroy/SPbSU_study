#include "network.h"

Network::Network(const QString &fileName)
{
	QFile input(fileName);
	if (!input.open(QIODevice::ReadOnly | QIODevice::Text))
			return;

	QTextStream in(&input);

	size = in.readLine().toInt();

	computers = new Computer[size];
	in.readLine();
	for (int i = 0; i < size; i++)
	{
		QString computerStatus = in.readLine();
		computers[i].setOperatingSystem((QChar)computerStatus[0]);
		computers[i].setInfectedStatus(computerStatus[2].digitValue());
	}

	connections = new int *[size];
	for (int i = 0; i < size; i++)
		connections[i] = new int[size];
	in.readLine();
	for (int i = 0; i < size; i++)
	{
		QString row = in.readLine();
		row.remove(QChar(' '));
		for (int j = 0; j < size; j++)
		{
			connections[i][j] = row[j].digitValue();
		}
	}
}

Network::~Network()
{
	for (int i = 0; i < size; i++)
		delete[] connections[i];
	delete[] connections;

	delete[] computers;
}

void Network::printStatus()
{
	std::cout << "Recently infected the following computers:\n";
	bool noRecentInfections = true;
	for (int i = 0; i< size; i++)
	{
		if (computers[i].isRecentlyInfected())
		{
			std::cout << "#" << i + 1 << "\n";
			noRecentInfections = false;
		}
	}
	if (noRecentInfections)
		std::cout << "none\n";
	std::cout << "\n";

	std::cout << "Number:    ";
	for (int i = 0; i < size; i++)
		std::cout << i + 1 << " ";
	std::cout << "\n";

	std::cout << "OS:        ";
	for (int i = 0; i < size; i++)
		std::cout << computers[i].getOperatingSystem().toLatin1() << " ";
	std::cout << "\n";

	std::cout << "Infection: ";
	for (int i = 0; i < size; i++)
		if (computers[i].isInfected())
			std::cout << "X ";
		else
			std::cout << "O ";
	std::cout << "\n";

	/*for (int i = 0; i < size; i++)
	{
		std::cout << "Computer #" << i << " ";

		QChar operatingSystem = computers[i].getOperatingSystem();
		switch (operatingSystem.toLatin1())
		{
			case 'W':
				std::cout << "Windows";
				break;
			case 'L':
				std::cout << "Linux  ";
				break;
			case 'M':
			std::cout << "Mac    ";
			break;
		}
		std::cout << " ";

		if (computers[i].isInfected())
			std::cout << "Infected";
		else
			std::cout << "Not infected";

		std::cout << "\n";
	}*/
}

void Network::spreadInfection()
{
	for (int i = 0; i < size; i++)
	{
		if (computers[i].isInfected())
			for (int j = 0; j < size; j++)
			{
				if (connections[i][j] == 1)
					computers[j].setRecentlyInfectedStatus(computers[j].tryToInfect());
			}
	}
}

void Network::spreadInfectionForSure()
{
	for (int i = 0; i < size; i++)
	{
		if (computers[i].isInfected())
			for (int j = 0; j < size; j++)
			{
				if (connections[i][j] == 1)
				{
					computers[j].setInfectedStatus(true);
					computers[j].setRecentlyInfectedStatus(true);
				}
			}
	}
}

bool Network::allInfected()
{
	for (int i = 0; i < size; i++)
		if (!computers[i].isInfected())
			return false;
	return true;
}

bool Network::computerInfected(int number)
{
	return computers[number].isInfected();
}


