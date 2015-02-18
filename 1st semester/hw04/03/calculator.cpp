#include <stdio.h>
#include "stackInt.h"
#include "calculator.h"

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
