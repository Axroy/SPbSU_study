#include "network.h"

void Network::clearBuffer()
{
	tcpSocket->readAll();
}

void Network::sendMessage(Message message)
{
	QByteArray block;
	QDataStream out(&block, QIODevice::WriteOnly);
	out.setVersion(QDataStream::Qt_4_0);
	out << (quint16)0;
	out << message;
	out.device()->seek(0);
	out << (quint16)(block.size() - sizeof(quint16));

	tcpSocket->write(block);
}

void Network::readMessage()
{
	QDataStream in(tcpSocket);
	in.setVersion(QDataStream::Qt_4_0);

	if (blockSize == 0)
	{
		if (tcpSocket->bytesAvailable() < (int)sizeof(quint16))
			return;

		in >> blockSize;
	}

	if (tcpSocket->bytesAvailable() < blockSize)
		return;

	int message;
	in >> message;
	blockSize = 0;

	emit messageReceived((Message)message);
}

void Network::lostConnection()
{
	statusLabel->setText("Disconnected");
	emit disconnected();
}

