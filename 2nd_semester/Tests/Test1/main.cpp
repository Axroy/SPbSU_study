#include <QCoreApplication>
#include "priorityQueue.h"
#include "priorityQueueTests.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //PriorityQueue<int> test;

    PriorityQueueTests tests;
    QTest::qExec(&tests);


    return a.exec();
}
