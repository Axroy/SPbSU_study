#pragma once

///Enumerable type for operations.
enum Operation
{
    plus,
    minus,
    multiply,
    divide
};

///Class for calculating simple integer expressions consisting of two numbers and one operation.
class SimpleCalculator
{
public:
    SimpleCalculator();

    ///Calculates the integer expression. Returns zero in case of dividing by it.
    int getResult();
    ///Changes first number to some value.
    void changeFirstNumber(int value);
    ///Changes second number to some value.
    void changeSecondNumber(int value);
    ///Changes operation to some operation type from certain enumerable.
    void changeOperation(Operation newOperation);

private:
    int firstNumber;
    int secondNumber;
    Operation operation;
};

