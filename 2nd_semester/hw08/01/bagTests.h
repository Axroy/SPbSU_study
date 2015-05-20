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

   void balancing()
   {
       bag->insert(1);
       bag->insert(2);
       bag->insert(3);
       QVERIFY(bag->height() == 2);
       QVERIFY(bag->exists(1) && bag->exists(2) && bag->exists(3));
   }

private:
   Bag *bag;
};
