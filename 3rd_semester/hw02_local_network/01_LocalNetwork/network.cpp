#include "network.h"

Network::Network() : size(10), connections(new int *[size]), computers(new Computer[size])
{
	for (int i = 0; i < size; i++)
		connections[i] = new int[size];
}

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

void Network::printStatus()
{
	//std::cout << size << "\n";

	for (int i = 0; i < size; i++)
	{
		std::cout << "Computer #" << i << " ";

		QChar operatingSystem = computers[i].getOperatingSystem();
		switch (operatingSystem.toLatin1())
		{
			case 'W':
				std::cout << "Windows";
				break;
			case 'L':
				std::cout << "Linux";
				break;
			case 'M':
			std::cout << "Mac";
			break;
		}
		std::cout << " ";

		if (computers[i].isInfected())
			std::cout << "Infected";
		else
			std::cout << "Not infected";

		std::cout << "\n";
	}

	/*for (int i = 0; i < size; i++)
	{
		std::cout << "\n";
		for (int j = 0; j < size; j++)
		{
			std::cout << connections[i][j] << " ";
		}
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
					computers[j].tryToInfect();
			}
	}
}

