#include <QCoreApplication>
#include "iteratorTests.h"

int main(int argc, char *argv[])
{
    IteratorTests tests;
    QTest::qExec(&tests);
    QCoreApplication a(argc, argv);

    return a.exec();
}
