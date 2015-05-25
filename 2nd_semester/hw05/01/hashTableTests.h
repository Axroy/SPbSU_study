#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "hashTable.h"

class HashTableTests : public QObject
{
   Q_OBJECT
public:
   explicit HashTableTests(QObject *parent = 0) : QObject(parent) {}

private slots:
   void init()
   {
       table = new HashTable(5);
   }

   void cleanup()
   {
       delete table;
   }

   void addingTest()
   {
       table->addValue("1");
       table->addValue("2");
       table->addValue("3");
       QVERIFY(table->numberOfFilledCells() == 3);
   }

   void conflictsAddingTest()
   {
       table->addValue("1");
       table->addValue("1");
       table->addValue("1");
       QVERIFY(table->numberOfFilledCells() == 1);
   }

   void removingTest()
   {
       table->addValue("1");
       table->addValue("2");
       table->addValue("3");
       table->removeValue("2");
       QVERIFY(table->numberOfFilledCells() == 2);
   }

   void differentHashTest()
   {
       table->addValue("1111");
       HashFunctions *newFunction = new SymbolsSumHash(5);
       table->changeHashFunction(newFunction);
       table->addValue("1111");
       QVERIFY(table->numberOfFilledCells() == 2);
   }

   void emptyTableTest()
   {
       QVERIFY(table->numberOfFilledCells() == 0);
   }

   void removingInexistentValueTest()
   {
       table->addValue("1");
       table->addValue("2");
       table->addValue("3");
       table->removeValue("4");
       QVERIFY(table->numberOfFilledCells() == 3);
   }

   void findingValueTest()
   {
       table->addValue("1");
       table->addValue("2");
       table->addValue("3");
       QVERIFY(table->findValue("3") == 1);
   }

   void findingInexistentValueTest()
   {
       table->addValue("1");
       QVERIFY(table->findValue("3") == -1);
   }

private:
   HashTable *table;
};
