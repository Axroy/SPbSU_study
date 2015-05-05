#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "polynomialHash.h"
#include "symbolsSumHash.h"

class hashFunctionsTests : public QObject
{
   Q_OBJECT
public:
   explicit hashFunctionsTests(QObject *parent = 0) : QObject(parent) {}

private slots:
   void polynomialHashTest()
   {
       PolynomialHash hashFunction(10);
       QVERIFY(hashFunction.hash("abc") == 2);
   }

   void symbolsSumHashTest()
   {
       SymbolsSumHash hashFunction(10);
       QVERIFY(hashFunction.hash("abc") == 4);
   }

   void polynomialHashTest2()
   {
       PolynomialHash hashFunction(10);
       QVERIFY(hashFunction.hash("") == 0);
   }

   void symbolsSumHashTest2()
   {
       SymbolsSumHash hashFunction(10);
       QVERIFY(hashFunction.hash("") == 0);
   }
};
