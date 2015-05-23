#include <iostream>
#include "pointerStack.h"

PointerStack::StackElement::StackElement(int value, PointerStack::StackElement *nextElement)
{
    data = value;
    next = nextElement;
}

PointerStack::PointerStack()
{
    top = new StackElement(0, nullptr);
}

PointerStack::~PointerStack()
{
    StackElement *current = top;
    StackElement *toRemove = top;
    while (current->next != nullptr)
    {
        current = current->next;
        delete toRemove;
        toRemove = current;
    }
    delete toRemove;
}

void PointerStack::push(int value)
{
    StackElement *newElement = new StackElement(value, top->next);
    top->next = newElement;
}

int PointerStack::pop()
{
    if (top->next == nullptr)
        return 0;

    int result = top->next->data;
    StackElement *toRemove = top->next;
    top->next = toRemove->next;
    delete toRemove;
    return result;
}

void PointerStack::print()
{
    StackElement *current = top;
    while (current->next != nullptr)
    {
        current = current->next;
        std::cout << current->data << " ";
    }
}

