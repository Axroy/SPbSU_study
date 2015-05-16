#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "uberCalculator.h"

class uberCalculatorTests : public QObject
{
   Q_OBJECT
public:
   explicit uberCalculatorTests(QObject *parent = 0) : QObject(parent) {}

private slots:

    void cleanup()
    {
        calc.reset();
    }

    void resettedStateResult()
    {
        QVERIFY(calc.getResult() == 0);
    }

    void addition()
    {
        calc.changeFirstArgument(10);
        calc.changeOperation(plus);
        calc.changeSecondArgument(12);
        QVERIFY(calc.getResult() == 22);
    }

    void substraction()
    {
        calc.changeFirstArgument(34);
        calc.changeOperation(minus);
        calc.changeSecondArgument(4);
        QVERIFY(calc.getResult() == 30);
    }

    void multiplication()
    {
        calc.changeFirstArgument(6.25);
        calc.changeOperation(multiply);
        calc.changeSecondArgument(8);
        QVERIFY(calc.getResult() == 50);
    }

    void division()
    {
        calc.changeFirstArgument(81);
        calc.changeOperation(divide);
        calc.changeSecondArgument(3);
        QVERIFY(calc.getResult() == 27);
    }

private:
    UberCalculator calc;
};
