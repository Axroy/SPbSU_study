#include <QCoreApplication>
#include <iostream>
#include <string>
#include "counter.h"
#include "parseTreeTests.h"

int main(int argc, char *argv[])
{
    ParseTreeTests tests;
    QTest::qExec(&tests);

    QCoreApplication a(argc, argv);
    std::cout << Counter::countExpression("file.txt");
    return a.exec();
}
