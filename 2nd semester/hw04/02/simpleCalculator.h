#pragma once

enum Operation
{
    plus,
    minus,
    multiply,
    divide
};

class SimpleCalculator
{
public:
    SimpleCalculator();

    int getResult();
    void changeFirstNumber(int value);
    void changeSecondNumber(int value);
    void changeOperation(Operation newOperation);

private:
    int firstNumber;
    int secondNumber;
    Operation operation;
};

