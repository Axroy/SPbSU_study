#pragma once

class Stack
{
public:
    virtual ~Stack(){}
    virtual void push(int value) = 0;
    virtual int pop(int value) = 0;
    virtual void print() = 0;
};
