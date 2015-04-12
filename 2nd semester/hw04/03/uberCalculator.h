#pragma once

enum Operation
{
    none,
    plus,
    minus,
    multiply,
    divide
};

class UberCalculator
{
public:
    UberCalculator();
    void changeFirstArgument(float value);
    void changeSecondArgument(float value);
    void changeOperation(Operation newOperation);
    bool hasNoOperation();

private:
    float firstArgument;
    float secondArgument;
    Operation operation;
};

