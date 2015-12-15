#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include <QtCore/QFile>
#include "network.h"

class NetworkTests : public QObject
{
   Q_OBJECT
public:
   explicit NetworkTests(QObject *parent = 0) : QObject(parent) {}

private slots:
   void cleanup()
   {
	   delete network;
   }

   //Should not crash probably
   void nullNetwork()
   {
	   QFile nullSize("nullSize.txt");
	   nullSize.open(QIODevice::WriteOnly | QIODevice::Text);
	   QTextStream out(&nullSize);
	   out << 0;
	   nullSize.close();

	   network = new Network("nullSize.txt");
	   network->spreadInfection();
   }

   void simpleInfection()
   {
	   QFile simpleInfection("simpleInfection.txt");
	   simpleInfection.open(QIODevice::WriteOnly | QIODevice::Text);
	   QTextStream out(&simpleInfection);
	   out << 2 << "\n\n";
	   out << "W 1\n" <<
			  "W 0\n" <<
			  "\n";
	   out << "0 1\n" <<
			  "1 0\n";
	   simpleInfection.close();

	   network = new Network("simpleInfection.txt");
	   network->spreadInfection(true);
	   QVERIFY(network->computerInfected(1));
   }

   void isolatedComputer()
   {
	   QFile isolatedComputer("isolatedComputer.txt");
	   isolatedComputer.open(QIODevice::WriteOnly | QIODevice::Text);
	   QTextStream out(&isolatedComputer);
	   out << 4 << "\n\n";
	   out << "W 1\n" <<
			  "W 0\n" <<
			  "W 0\n" <<
			  "W 0\n" <<
			  "\n";
	   out << "0 1 1 0\n" <<
			  "1 0 1 0\n" <<
			  "1 1 0 0\n" <<
			  "0 0 0 0\n";
	   isolatedComputer.close();

	   network = new Network("isolatedComputer.txt");
	   network->spreadInfection(true);
	   QVERIFY(!network->computerInfected(3));
   }

   void farAwayComputer()
   {
	   QFile farAwayComputer("farAwayComputer.txt");
	   farAwayComputer.open(QIODevice::WriteOnly | QIODevice::Text);
	   QTextStream out(&farAwayComputer);
	   out << 10 << "\n\n";
	   out << "W 1\n" <<
			  "W 0\n" <<
			  "W 0\n" <<
			  "W 0\n" <<
			  "W 0\n" <<
			  "W 0\n" <<
			  "W 0\n" <<
			  "W 0\n" <<
			  "W 0\n" <<
			  "W 0\n" <<
			  "\n";
	   out << "0 1 0 0 0 0 0 0 0 0\n" <<
			  "1 0 1 0 0 0 0 0 0 0\n" <<
			  "0 1 0 1 0 0 0 0 0 0\n" <<
			  "0 0 1 0 1 0 0 0 0 0\n" <<
			  "0 0 0 1 0 1 0 0 0 0\n" <<
			  "0 0 0 0 1 0 1 0 0 0\n" <<
			  "0 0 0 0 0 1 0 1 0 0\n" <<
			  "0 0 0 0 0 0 1 0 1 0\n" <<
			  "0 0 0 0 0 0 0 1 0 1\n" <<
			  "0 0 0 0 0 0 0 0 1 0\n";
	   farAwayComputer.close();

	   network = new Network("farAwayComputer.txt");
	   network->spreadInfection(true);
	   QVERIFY(network->computerInfected(9));
   }

private:
   Network *network;
};
