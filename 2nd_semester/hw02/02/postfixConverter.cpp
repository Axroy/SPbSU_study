#include "postfixConverter.h"

PostfixConverter::PostfixConverter()
{
    top = new StackElement('0', nullptr);
}

PostfixConverter::~PostfixConverter()
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

void PostfixConverter::push(char value)
{
    StackElement *newElement = new StackElement(value, top->next);
    top->next = newElement;
}

int PostfixConverter::pop()
{
    int result = top->next->data;
    StackElement *toRemove = top->next;
    top->next = toRemove->next;
    delete toRemove;
    return result;
}

bool PostfixConverter::isEmpty()
{
    return top->next == nullptr;
}

int PostfixConverter::topData()
{
    return top->next->data;
}


PostfixConverter::StackElement::StackElement(char value, PostfixConverter::StackElement *nextElement)
{
    data = value;
    next = nextElement;
}
