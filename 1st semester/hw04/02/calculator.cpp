#include <stdio.h>
#include "stackChar.h"
#include "calculator.h"

int operationPriority(char operation)
{
    switch (operation)
    {
        case '*':
        case '/':
            return 2;
            break;

        case '+':
        case '-':
            return 1;
            break;

        case '(':
            return 0;
            break;
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
