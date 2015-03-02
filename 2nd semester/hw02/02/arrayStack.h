#pragma once

#include "stack.h"

class ArrayStack : public Stack
{
public:
    ArrayStack(int arraySize);
    ~ArrayStack();
    void push(int value);
    int pop();
    void print();

private:
    int *array;
    int top;
    int size;
};

