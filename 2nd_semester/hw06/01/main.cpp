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
    std::cout << ("\nThe program for calculating arithmetical expressions using parse tree.\n");

    std::string fileName = "";
    std::cout << ("Enter a name of file containing the expression in prefix form:\n");
    std::cin >> fileName;

    std::cout << "Your result: " << Counter::countExpressionWithPrinting(fileName);

    return a.exec();
}
