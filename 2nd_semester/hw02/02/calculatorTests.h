#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "calculator.h"

class CalculatorTests : public QObject
{
   Q_OBJECT
public:
   explicit CalculatorTests(QObject *parent = 0) : QObject(parent) {}

private slots:

    void calculatingTest()
    {
        QVERIFY(calc.count("2 + 2") == 4);
    }

    void calculatingTest2()
    {
        QVERIFY(calc.count("(2 + 2) * 4") == 16);
    }

    void calculatingTest3()
    {
        QVERIFY(calc.count("(2 + 2) * (6 / 3) / 7") == 1);
    }

    void constantExpressionTest()
    {
        QVERIFY(calc.count("8") == 8);
    }

    void emptyExpressionTest()
    {
        QVERIFY(calc.count("") == 0);
    }

    void expressionWithoutSpacesTest()
    {
        QVERIFY(calc.count("(2+2)*(6/3)/7") == 1);
    }

    void expressionWithManySpacesTest()
    {
        QVERIFY(calc.count("8      /   4") == 2);
    }

private:
   Calculator calc;
};
