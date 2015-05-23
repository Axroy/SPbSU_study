#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "vector.h"

class VectorTests : public QObject
{
   Q_OBJECT
public:
    explicit VectorTests(QObject *parent = 0) : QObject(parent) {}

private slots:

    void init()
    {
        size = 15;

        coordinates1 = new int[size];
        for (int i = 0; i < size; i++)
            coordinates1[i] = i;

        coordinates2 = new int[size];
        for (int i = 0; i < size; i++)
            coordinates2[i] = i * 2;
    }

    void cleanup()
    {
        delete[] coordinates1;
        delete[] coordinates2;
    }

    void nullVector()
    {
        Vector<int> vector;
        QVERIFY(vector.isNull());
    }

    void creation()
    {
        Vector<int> vector(size, coordinates1);
        QVERIFY(vector.getSize() == size);
        for (int i = 0; i < size; i++)
            QVERIFY(vector.at(i) == i);
    }

    void copying()
    {
        Vector<int> vector1(size, coordinates1);
        Vector<int> vector2(vector1);
        QVERIFY(vector1 == vector2);
    }

    void addition()
    {
        Vector<int> vector1(size, coordinates1);
        Vector<int> vector2(size, coordinates2);
        vector2 = vector1 + vector2;
        for (int i = 0; i < size; i++)
            QVERIFY(vector2.at(i) == i * 3);
    }

    void additionException()
    {
        Vector<int> vector1(size, coordinates1);
        Vector<int> vector2;
        QVERIFY_EXCEPTION_THROWN(vector2 = vector1 + vector2, DifferentSizes);
    }

    void substraction()
    {
        Vector<int> vector1(size, coordinates1);
        Vector<int> vector2(size, coordinates2);
        vector2 = vector2 - vector1;
        for (int i = 0; i < size; i++)
            QVERIFY(vector2.at(i) == i);
    }

    void substractionException()
    {
        Vector<int> vector1(size, coordinates1);
        Vector<int> vector2;
        QVERIFY_EXCEPTION_THROWN(vector2 = vector1 - vector2, DifferentSizes);
    }

    void scalarMultiplication()
    {
        Vector<int> vector(size, coordinates1);
        vector = vector * 5;
        for (int i = 0; i < size; i++)
            QVERIFY(vector.at(i) == i * 5);
    }

private:
    int* coordinates1;
    int* coordinates2;
    int size;
};
