#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "bag.h"

class BagTests : public QObject
{
   Q_OBJECT
public:
   explicit BagTests(QObject *parent = 0) : QObject(parent) {}

private slots:
   void init()
   {
       bag = new Bag();
   }

   void cleanup()
   {
       delete bag;
   }

   void empty()
   {
       QVERIFY(bag->isEmpty());
   }

   void addition()
   {
       bag->insert(12);
       bag->insert(-12);
       QVERIFY(bag->exists(12));
       QVERIFY(bag->exists(-12));
   }

   void additionWithBalancing()
   {
       bag->insert(1);
       bag->insert(2);
       bag->insert(3);
       QVERIFY(bag->height() == 2);
       QVERIFY(bag->exists(1) && bag->exists(2) && bag->exists(3));
   }

   void removal()
   {
       bag->insert(4);
       bag->insert(34);
       bag->remove(34);
       QVERIFY(!bag->exists(34));
       QVERIFY(bag->exists(4));
   }

   void removalWithBalancing()
   {
       bag->insert(1);
       bag->insert(2);
       bag->insert(4);
       bag->insert(5);
       bag->remove(1);
       QVERIFY(!bag->exists(1));
       QVERIFY(bag->height() == 2);
   }

   void checkExistenceOfNonExistent()
   {
       QVERIFY(!bag->exists(0));
   }

   void printing()
   {
       bag->insert(56);
       bag->insert(0);
       bag->insert(12);
       bag->insert(-90);
       bag->insert(20);
       QString correctResult = "(12 (0 (-90 null null) null) (56 (20 null null) null) )";
       QVERIFY(bag->print() == correctResult);
   }

private:
   Bag *bag;
};
