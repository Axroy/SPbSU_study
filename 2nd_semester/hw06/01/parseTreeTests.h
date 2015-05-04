#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "parseTree.h"

class ParseTreeTests : public QObject
{
   Q_OBJECT
public:
   explicit ParseTreeTests(QObject *parent = 0) : QObject(parent) {}

private slots:
   void init()
   {
       tree = new ParseTree();
   }

   void cleanup()
   {
       delete tree;
   }

   void empty()
   {
       QVERIFY(tree->isEmpty());
   }

   void buldingSmallExpression()
   {
       tree->build("+ 2 2");
       QVERIFY(tree->getSize() == 3);
   }

   void buildingBigExpression()
   {
       tree->build("+ (* 5 1) (/ 8 2)");
       QVERIFY(tree->getSize() == 7);
   }

   void countingExampleExpression()
   {
       tree->build("(* (+ 1 1) 2)");
       QVERIFY(tree->count() == 4);
   }

   void countingLargeExpression()
   {
       tree->build("(- (/ 9 3) (* (+ 1 1) (* 8 6)))");
       QVERIFY(tree->count() == -93);
   }

private:
   ParseTree *tree;
};
