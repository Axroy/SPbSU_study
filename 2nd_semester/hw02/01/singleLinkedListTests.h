#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "singleLinkedList.h"

class SingleLinkedListTests : public QObject
{
   Q_OBJECT
public:
   explicit SingleLinkedListTests(QObject *parent = 0) : QObject(parent) {}

private slots:
   void init()
   {
       list = new SingleLinkedList();
   }

   void cleanup()
   {
       delete list;
   }

   void emptyTest()
   {
       QVERIFY(list->getSize() == 0);
   }

   void addingTest()
   {
       list->add(1);
       list->add(2);
       list->add(3);
       QVERIFY(list->getSize() == 3);
   }

   void removingTest()
   {
       list->add(1);
       list->add(2);
       list->add(3);
       list->remove(1);
       list->remove(3);
       QVERIFY(list->getSize() == 1);
   }

   void removingInexsistentValueTest()
   {
       list->add(1);
       list->add(2);
       list->add(3);
       list->remove(4);
       QVERIFY(list->getSize() == 3);
   }

   void emptyRemovingTest()
   {
       list->remove(4);
       QVERIFY(list->getSize() == 0);
   }

private:
   SingleLinkedList *list;
};
