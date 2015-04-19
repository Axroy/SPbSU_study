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
       table = new HashTable(10);
   }

   void cleanup()
   {
       delete table;
   }

   void addingValue()
   {
       table->addValue("1");
       QVERIFY(table->numberOfEmptyCells() == 9);
   }

   void removingValue()
   {
       table->addValue("1");
       table->addValue("2");
       table->addValue("3");

       table->removeValue("2");
       QVERIFY(table->numberOfEmptyCells() == 8);
   }

private:
   HashTable *table;
};
