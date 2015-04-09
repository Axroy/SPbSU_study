#include "simpleCalculator.h"

SimpleCalculator::SimpleCalculator() : firstNumber(0), secondNumber(0), operation(plus)
{
}

int SimpleCalculator::getResult()
{
    switch (operation)
    {
        case plus:
            return firstNumber + secondNumber;
            break;

        case minus:
            return firstNumber - secondNumber;
            break;

        case multiply:
            return firstNumber * secondNumber;
            break;

        case divide:
            if (secondNumber != 0)
                return firstNumber / secondNumber;
            else
                return 0;
            break;
    }
}

void SimpleCalculator::changeFirstNumber(int value)
{
    firstNumber = value;
}

void SimpleCalculator::changeSecondNumber(int value)
{
    secondNumber = value;
}

void SimpleCalculator::changeOperation(Operation newOperation)
{
    operation = newOperation;
}
