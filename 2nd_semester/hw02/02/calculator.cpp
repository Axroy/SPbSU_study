#include "calculator.h"

const int maxStringSize = 100;

Calculator::Calculator()
{
}

int Calculator::count(char *string)
{
    char postfixString[maxStringSize] = "";
    convertToPostfix(string, postfixString);
    return postfixCount(postfixString);
}

int Calculator::operationPriority(char operation)
{
    switch (operation)
        {
            case '*':
            case '/':
                return 2;

            case '+':
            case '-':
                return 1;

            case '(':
                return 0;
        }
    return -1;
}

int Calculator::doOperation(int a, int b, char operation)
{
    switch (operation)
        {
            case '*':
                return a * b;
            case '/':
                return a / b;
            case '+':
                return a + b;
            case '-':
                return a - b;
        }
    return -1;
}

int Calculator::postfixCount(char *string)
{
    PointerStack *stack = new PointerStack;
    int numA = 0;
    int numB = 0;
    int i = 0;
    while (string[i] != '\n')
    {
        switch (string[i])
        {
            case '*':
            case '/':
            case '+':
            case '-':
                numA = stack->pop();
                numB = stack->pop();
                stack->push(doOperation(numB, numA, string[i]));
                break;

            case ' ':
                break;

            default:
                stack->push(string[i] - '0');
        }
        i++;
    }
    int result = stack->pop();
    delete stack;
    return result;
}

void Calculator::convertToPostfix(char *string, char *resultingString)
{
    PostfixConverter *converter = new PostfixConverter;
    int i = 0;
    int resStrPosition = 0;
    while (string[i] != '\0' && string[i] != '\n')
    {
        switch (string[i])
        {
            case '*':
            case '/':
            case '+':
            case '-':
                if (!converter->isEmpty() && operationPriority(string[i]) <= operationPriority(converter->topData()))
                {
                    resultingString[resStrPosition] = converter->pop();
                    resultingString[resStrPosition + 1] = ' ';
                    resStrPosition = resStrPosition + 2;
                }
                converter->push(string[i]);
                break;

            case ' ':
                break;

            case '(':
                converter->push(string[i]);
                break;

            case ')':
                while (!converter->isEmpty() && converter->topData() != '(')
                {
                    resultingString[resStrPosition] = converter->pop();
                    resultingString[resStrPosition + 1] = ' ';
                    resStrPosition = resStrPosition + 2;
                }
                if (!converter->isEmpty())
                    converter->pop();
                break;

            default:
                resultingString[resStrPosition] = string[i];
                resultingString[resStrPosition + 1] = ' ';
                resStrPosition = resStrPosition + 2;
        }
        i++;
    }

    while (!converter->isEmpty())
    {
        resultingString[resStrPosition] = converter->pop();
        resultingString[resStrPosition + 1] = ' ';
        resStrPosition = resStrPosition + 2;

    }

    resultingString[resStrPosition] = '\n';
    delete converter;
}
