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
    }
}
