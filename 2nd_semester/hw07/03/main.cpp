#include <QCoreApplication>
#include <iostream>
#include "sharedPointer.h"
#include "sharedPointerTests.h"


int main(int argc, char *argv[])
{
    SharedPointerTests tests;
    QTest::qExec(&tests);

    QCoreApplication a(argc, argv);

    return a.exec();
}
