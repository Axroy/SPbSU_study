#pragma once

///Enumerable for more convenient use of operations.
enum Operation
{
    none,
    plus,
    minus,
    multiply,
    divide
};

///Class for handling the UberCalculatorUI form.
///Calculates expressions consisting of two arguments and an operation.
class UberCalculator
{
public:
    UberCalculator();

    ///Changes first argument to certain value.
    void changeFirstArgument(float value);

    ///Changes second argument to certain value.
    void changeSecondArgument(float value);

    ///Changes operation to certain operation type from the enumerable.
    void changeOperation(Operation newOperation);

    ///Returns true if operation type is 'none'.
    bool hasNoOperation();

    ///Calculates the expression and return result.
    float getResult();

    ///Resets arguments and operation to default.
    void reset();

private:
    float firstArgument;
    float secondArgument;
    Operation operation;
};

