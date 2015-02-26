#pragma once

#include "pointerStack.h"
#include "postfixConverter.h"

class Calculator
{
public:
    Calculator();
    int count(char *string);

private:
    int operationPriority(char operation);
    int doOperation(int a, int b, char operation);
    int postfixCount(char *string);
    void convertToPostfix(char *string, char *resultingString);

};

