#include <QCoreApplication>
#include <iostream>
#include "vector.h"
#include "vectorTests.h"

int main(int argc, char *argv[])
{
    VectorTests tests;
    QTest::qExec(&tests);

    QCoreApplication a(argc, argv);

    return a.exec();
}
