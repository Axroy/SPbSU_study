#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "hashFunctions.h"

class hashFunctionsTests : public QObject
{
   Q_OBJECT
public:
   explicit hashFunctionsTests(QObject *parent = 0) : QObject(parent) {}

private slots:
   void init()
   {
       functions = new HashFunctions(10);
   }

   void cleanup()
   {
       delete functions;
   }

   void polynomialHashTest()
   {
       QVERIFY(functions->generateHash("abc") == 2);
   }

   void symbolsSumHashTest()
   {
       functions->changeFunction(symbolsSum);
       QVERIFY(functions->generateHash("abc") == 4);
   }

   void polynomialHashTest2()
   {
       QVERIFY(functions->generateHash("") == 0);
   }

   void symbolsSumHashTest2()
   {
       functions->changeFunction(symbolsSum);
       QVERIFY(functions->generateHash("") == 0);
   }

private:
   HashFunctions *functions;
};
