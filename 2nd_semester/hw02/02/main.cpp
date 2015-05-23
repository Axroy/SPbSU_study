#include <iostream>
#include "calculator.h"

#include "calculatorTests.h"


int main()
{
    CalculatorTests calcTests;
    QTest::qExec(&calcTests);

    std::cout << "The program calculates mathematical expressions.\n";
    std::cout << "Only works with single-character numbers.\n";
    std::cout << "Enter the expression:\n";

    const int size = 1000;
    char string[size] = "";
    fgets(string, size, stdin);

    Calculator calc;
    std::cout << "\n\nResult: " << calc.count(string);


    return 0;
}

