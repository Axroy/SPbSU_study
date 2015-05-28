#pragma once


#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "iterator.h"
#include "binaryTree.h"

class IteratorTests : public QObject
{
   Q_OBJECT
public:
   explicit IteratorTests(QObject *parent = 0) : QObject(parent) {}

private slots:
   void init()
   {
       tree = new BinaryTree();
       tree->insert(10);
       tree->insert(3);
       tree->insert(15);
       tree->insert(1);
       tree->insert(4);
       tree->insert(12);
       tree->insert(20);
   }

   void cleanup()
   {
       delete tree;
   }

   void nextTest()
   {
       Iterator iterator(tree);
       QVERIFY(iterator.next() == 10);
   }

   void isEmptyTest()
   {
       Iterator iterator(tree);
       iterator.next();
       iterator.next();
       iterator.next();
       QVERIFY(iterator.isEmpty());
   }

   void resetTest()
   {
       Iterator iterator(tree);
       iterator.next();
       iterator.next();
       iterator.next();
       iterator.reset();
       QVERIFY(iterator.next() == 10);
   }

   void removeTest()
   {
       Iterator iterator(tree);
       iterator.next();
       iterator.next();
       iterator.remove();
       iterator.reset();
       iterator.next();
       iterator.next();
       QVERIFY(iterator.next() == 4);
   }

private:
   BinaryTree *tree;
};
