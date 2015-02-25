#include <iostream>
#include "arrayStack.h"

ArrayStack::ArrayStack(int arraySize)
{
    size = arraySize;
    top = 0;
    array = new int[size];
}

ArrayStack::~ArrayStack()
{
    delete[] array;
}

void ArrayStack::push(int value)
{
    if (top >= size)
        return;
    array[top] = value;
    top++;
}

int ArrayStack::pop()
{

}

void ArrayStack::print()
{
    for (int i = 0; i < top; i++)
        std::cout << array[i] << " ";
}
