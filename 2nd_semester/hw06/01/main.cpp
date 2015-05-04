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
    printf("The program for calculating arithmetical expressions using parse tree.\n");

    std::string fileName = "";
    printf("Enter a name of file containing the expression in prefix form:\n");
    std::cin >> fileName;

    std::cout << Counter::countExpression(fileName);

    return a.exec();
}
