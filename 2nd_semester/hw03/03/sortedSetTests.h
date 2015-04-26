#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "sortedSet.h"

class SortedSetTests : public QObject
{
   Q_OBJECT
public:
   explicit SortedSetTests(QObject *parent = 0) : QObject(parent) {}

private slots:

    void init()
    {
        set = new SortedSet();
    }

    void cleanup()
    {
        delete set;
    }

    void emptyTest()
    {
        QVERIFY(set->getSize() == 0);
    }

    void additionTest()
    {
        LinkedList *list1 = new LinkedList;
        LinkedList *list2 = new LinkedList;
        set->add(list1);
        set->add(list2);
        QVERIFY(set->getSize() == 2);
        delete list1;
        delete list2;
    }

    void sameListMultipleAdditionTest()
    {
        LinkedList *list = new LinkedList;
        set->add(list);
        set->add(list);
        set->add(list);
        QVERIFY(set->getSize() == 3);
        delete list;
    }

    void removalTest()
    {
        LinkedList *list1 = new LinkedList;
        LinkedList *list2 = new LinkedList;
        set->add(list1);
        set->add(list2);
        set->remove(list1);
        QVERIFY(set->getSize() == 1);
        delete list1;
        delete list2;
    }

    void emptyRemovalTest()
    {
        LinkedList *list = new LinkedList;
        set->remove(list);
        QVERIFY(set->getSize() == 0);
        delete list;
    }



private:
   SortedSet *set;
};
