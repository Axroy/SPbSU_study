#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "list.h"

class ListTests : public QObject
{
   Q_OBJECT
public:
   explicit ListTests(QObject *parent = 0) : QObject(parent) {}

private slots:
   void init()
   {
       list = new List;
   }

   void cleanup()
   {
       delete list;
   }

   void emptyTest()
   {
       QVERIFY(list->isEmpty());
   }

   void addingTest()
   {
       list->add("1");
       list->add("2");
       QVERIFY(list->numberOfElements() == 2);
   }

   void removingTest()
   {
       list->add("1");
       list->add("2");
       list->remove("1");
       QVERIFY(list->numberOfElements() == 1 && !list->hasValue("1"));
   }

   void removingInexsistentValueTest()
   {
       list->add("1");
       list->remove("100500");
       QVERIFY(list->numberOfElements() == 1);
   }

   void emptyRemovingTest()
   {
       list->remove("100500");
       QVERIFY(list->isEmpty());
   }

   void hasValueTest()
   {
       list->add("1");
       list->add("2");
       QVERIFY(list->hasValue("1"));
   }

   void hasInexsistentValueTest()
   {
       QVERIFY(!list->hasValue("1"));
   }

private:
   List *list;
};
