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
