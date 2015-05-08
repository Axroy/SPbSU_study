#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "uniqueList.h"

class UniqueListTests : public QObject
{
   Q_OBJECT
public:
   explicit UniqueListTests(QObject *parent = 0) : QObject(parent) {}

private slots:
   void init()
   {
       list = new UniqueList();
   }

   void cleanup()
   {
       delete list;
   }

   void addition()
   {
       list->add(1);
       list->add(-20);
       QVERIFY(list->exists(1) && list->exists(-20));
       QVERIFY(list->getSize() == 2);
   }

   void removal()
   {
       list->add(65);
       list->add(0);
       list->add(12);
       list->remove(0);
       QVERIFY(list->exists(65) && list->exists(12));
       QVERIFY(!list->exists(0));
       QVERIFY(list->getSize() == 2);
   }

   void additionException()
   {
       list->add(1);
       list->add(-20);
       QVERIFY_EXCEPTION_THROWN(list->add(1), AdditionOfExisting);
   }

   void removalException()
   {
       list->add(100);
       QVERIFY_EXCEPTION_THROWN(list->remove(-100), RemovalOfNonExisting);
   }

private:
   UniqueList *list;
};
