#pragma once

#include "stack.h"

class PointerStack : public Stack
{
public:
    PointerStack();
    ~PointerStack();
    void push(int value);
    int pop(int value);
    void print();

private:
    class StackElement
    {
    public:
        StackElement(int value, StackElement *nextElement);

        int data;
        StackElement *next;
    };

    StackElement *top;
};
