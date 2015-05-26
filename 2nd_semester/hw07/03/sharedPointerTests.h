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

    void removal()
    {
        SharedPointer<int> pointer(new int[10]);
        pointer.remove();
        QVERIFY(pointer.getLinksNumber() == 0);
    }

    void differentObjects()
    {
        SharedPointer<int> pointer1(new int[5]);
        SharedPointer<int> pointer2(new int[2]);
        QVERIFY(pointer1.getLinksNumber() == 1);
        QVERIFY(pointer2.getLinksNumber() == 1);
    }

    void copying()
    {
        SharedPointer<int> pointer1(new int[9]);
        SharedPointer<int> pointer2(pointer1);
        QVERIFY(pointer2.getLinksNumber() == 2);
    }

    void multipleCopying()
    {
        SharedPointer<float> pointer1(new float[5]);
        SharedPointer<float> pointer2(pointer1);
        SharedPointer<float> pointer3(pointer2);
        SharedPointer<float> pointer4(pointer3);
        SharedPointer<float> pointer5(pointer2);
        QVERIFY(pointer1.getLinksNumber() == 5);
    }

    void assignmentOperator()
    {
        SharedPointer<int> pointer1(new int[2]);
        SharedPointer<int> pointer2 = pointer1;
        QVERIFY(pointer2.getLinksNumber() == 2);
    }

    void multipleAssignment()
    {
        SharedPointer<char> pointer1(new char[7]);
        SharedPointer<char> pointer2 = pointer1;
        SharedPointer<char> pointer3 = pointer2;
        SharedPointer<char> pointer4 = pointer3;
        SharedPointer<char> pointer5 = pointer2;
        QVERIFY(pointer1.getLinksNumber() == 5);
    }

    void noObjectCopying()
    {
        SharedPointer<char> pointer1;
        SharedPointer<char> pointer2(pointer1);
        QVERIFY(pointer1.getLinksNumber() == 0);
    }

    void noObjectAssignment()
    {
        SharedPointer<char> pointer1;
        SharedPointer<char> pointer2 = pointer1;
        QVERIFY(pointer1.getLinksNumber() == 0);
    }
};
