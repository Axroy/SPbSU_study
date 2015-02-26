#pragma once

class PostfixConverter
{
public:
    PostfixConverter();
    ~PostfixConverter();
    void push(char value);
    int pop();
    bool isEmpty();
    int topData();

private:
    class StackElement
    {
    public:
        StackElement(char value, StackElement *nextElement);

        char data;
        StackElement *next;
    };

    StackElement *top;
};

