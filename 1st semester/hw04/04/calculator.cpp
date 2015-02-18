#include <stdio.h>
#include "stackInt.h"
#include "stackChar.h"
#include "calculator.h"

int operationPriority(char operation)
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
}

void convertToPostfix(StackChar *stack, char *string, char *resultingString)
{
    int i = 0;
    int resStrPosition = 0;
    while (string[i] != '.')
    {
        switch (string[i])
        {
            case '*':
            case '/':
            case '+':
            case '-':
                if (!isEmptyChar(stack) && operationPriority(string[i]) <= operationPriority(topChar(stack)))
                {
                    resultingString[resStrPosition] = popChar(stack);
                    resultingString[resStrPosition + 1] = ' ';
                    resStrPosition = resStrPosition + 2;
                }
                pushChar(stack, string[i]);
                break;

            case ' ':
                break;

            case '(':
                pushChar(stack, string[i]);
                break;

            case ')':
                while (!isEmptyChar(stack) && topChar(stack) != '(')
                {
                    resultingString[resStrPosition] = popChar(stack);
                    resultingString[resStrPosition + 1] = ' ';
                    resStrPosition = resStrPosition + 2;
                }
                if (!isEmptyChar(stack))
                    popChar(stack);
                break;

            default:
                resultingString[resStrPosition] = string[i];
                resultingString[resStrPosition + 1] = ' ';
                resStrPosition = resStrPosition + 2;
        }
        i++;
    }

    while (!isEmptyChar(stack))
    {
        resultingString[resStrPosition] = popChar(stack);
        resultingString[resStrPosition + 1] = ' ';
        resStrPosition = resStrPosition + 2;

    }

    resultingString[resStrPosition] = '.';

}

int count(int a, int b, char operation)
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
}

int postfixCount(Stack *stack, char *string)
{
    int numA = 0;
    int numB = 0;
    int i = 0;
    while (string[i] != '.')
    {
        switch (string[i])
        {
            case '*':
            case '/':
            case '+':
            case '-':
                numA = pop(stack);
                numB = pop(stack);
                push(stack, count(numB, numA, string[i]));
                break;

            case ' ':
                break;

            default:
                push(stack, string[i] - '0');
        }
        i++;
    }
    return top(stack);
}

