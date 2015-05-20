#include <QCoreApplication>
#include "bag.h"
#include "bagTests.h"

int main(int argc, char *argv[])
{
    BagTests tests;
    QTest::qExec(&tests);

    QCoreApplication a(argc, argv);

    return a.exec();
}
