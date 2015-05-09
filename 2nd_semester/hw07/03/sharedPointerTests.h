#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "sharedPointer.h"

class SharedPointerTests : public QObject
{
   Q_OBJECT
public:
   explicit SharedPointerTests(QObject *parent = 0) : QObject(parent) {}

private slots:
    void noObject()
    {
        SharedPointer<char> pointer;
        QVERIFY(pointer.getLinksNumber() == 0);
    }

    void creating()
    {
        SharedPointer<int> pointer(new int[5]);
        QVERIFY(pointer.getLinksNumber() == 1);
    }

    void copying()
    {
        SharedPointer<int> pointer1(new int[9]);
        SharedPointer<int> pointer2(pointer1);
        QVERIFY(pointer2.getLinksNumber() == 2);
    }

    void assignmentOperator()
    {
        SharedPointer<int> pointer1(new int[2]);
        SharedPointer<int> pointer2 = pointer1;
        QVERIFY(pointer2.getLinksNumber() == 2);
    }
};
