#include <QCoreApplication>
#include "priorityQueue.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    PriorityQueue<int> test;


    return a.exec();
}
