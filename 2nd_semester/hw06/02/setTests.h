#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "set.h"

class SetTests : public QObject
{
   Q_OBJECT
public:
   explicit SetTests(QObject *parent = 0) : QObject(parent) {}

private slots:
   void init()
   {
       set = new Set<int>;
   }

   void cleanup()
   {
       delete set;
   }

   void addition()
   {
       set->add(1);
       set->add(-20);
       set->add(-20);
       QVERIFY(set->exists(1) && set->exists(-20));
       QVERIFY(set->getSize() == 2);
   }

   void removal()
   {
       set->add(65);
       set->add(0);
       set->add(12);
       set->remove(0);
       QVERIFY(set->exists(65) && set->exists(12));
       QVERIFY(!set->exists(0));
       QVERIFY(set->getSize() == 2);
   }

   void removingInexsistentValue()
   {
       set->add(5);
       set->add(-250);
       set->remove(0);
       QVERIFY(set->exists(5) && set->exists(-250));
       QVERIFY(set->getSize() == 2);
   }

   void intersection()
   {
       set->add(-95);
       set->add(66);
       set->add(8);

       Set<int> *set2 = new Set<int>;
       set2->add(66);
       set2->add(8);
       set2->add(10);

       Set<int> *intersectedSet = set->intersection(set2);
       QVERIFY(intersectedSet->exists(66) && intersectedSet->exists(8));
       QVERIFY(!intersectedSet->exists(-95) && !intersectedSet->exists(10));
       QVERIFY(intersectedSet->getSize() == 2);

       delete set2;
       delete intersectedSet;
   }

   void association()
   {
       set->add(45);
       set->add(-22);

       Set<int> *set2 = new Set<int>;
       set2->add(6);
       set2->add(3);

       Set<int> *associatedSet = set->association(set2);
       QVERIFY(associatedSet->exists(45) && associatedSet->exists(-22));
       QVERIFY(associatedSet->exists(6) && associatedSet->exists(3));
       QVERIFY(associatedSet->getSize() == 4);

       delete set2;
       delete associatedSet;
   }

private:
   Set<int> *set;
};
