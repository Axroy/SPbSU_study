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

	}

	connections = new int *[size];
	for (int i = 0; i < size; i++)
		connections[i] = new int[size];
}

