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
    float getResult();
    void reset();

private:
    float firstArgument;
    float secondArgument;
    Operation operation;
};

