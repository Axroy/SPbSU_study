#pragma once


#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "priorityQueue.h"

class PriorityQueueTests : public QObject
{
   Q_OBJECT
public:
   explicit PriorityQueueTests(QObject *parent = 0) : QObject(parent) {}

private slots:
   void init()
   {
       queue = new PriorityQueue<int>;
   }

   void enqueuingTest()
   {
       queue->enqueue(1, 5);
       queue->enqueue(2, 3);
       queue->enqueue(3, 10);
       QVERIFY(queue->getFirstValue() == 3);
   }

private:
   PriorityQueue<int> *queue;
};
