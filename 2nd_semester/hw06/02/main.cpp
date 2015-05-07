#include <QCoreApplication>
#include "set.h"
#include "setTests.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    SetTests tests;
    QTest::qExec(&tests);

    return a.exec();
}
