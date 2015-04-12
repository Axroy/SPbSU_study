#include "uberCalculator.h"

UberCalculator::UberCalculator() : firstArgument(0), secondArgument(0), operation(none)
{
}

void UberCalculator::changeFirstArgument(float value)
{
    firstArgument = value;
}

void UberCalculator::changeSecondArgument(float value)
{
    secondArgument = value;
}

void UberCalculator::changeOperation(Operation newOperation)
{
    operation = newOperation;
}

bool UberCalculator::hasNoOperation()
{
    return operation == none;
}

float UberCalculator::getResult()
{
    switch (operation)
    {
        case plus:
            return firstArgument + secondArgument;
            break;

        case minus:
            return firstArgument - secondArgument;
            break;

        case multiply:
            return firstArgument * secondArgument;
            break;

        case divide:
            return firstArgument / secondArgument;
            break;
    }
}

void UberCalculator::reset()
{
    firstArgument = 0;
    secondArgument = 0;
    operation = none;
}
