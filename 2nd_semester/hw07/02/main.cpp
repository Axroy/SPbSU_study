#include <QCoreApplication>
#include "uniqueList.h"
#include "uniqueListTests.h"

int main(int argc, char *argv[])
{
    UniqueListTests tests;
    QTest::qExec(&tests);

    QCoreApplication a(argc, argv);

    return a.exec();
}
