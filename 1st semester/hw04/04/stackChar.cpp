#include <stdio.h>
#include "stackChar.h"

struct StackCharElement
{
    char value;
    StackCharElement *next;
};


struct StackChar
{
    StackCharElement *top;
};

StackCharElement *createStackCharElement(char value, StackCharElement *next)
{
    StackCharElement *newStackElement = new StackCharElement;
    newStackElement->next = next;
    newStackElement->value = value;
    return newStackElement;
}


StackChar *createStackChar()
{
    StackChar *newStack = new StackChar;
    newStack->top = createStackCharElement(0, nullptr);
    return newStack;
}


void pushChar(StackChar *stack, char value)
{
    StackCharElement *newElement = createStackCharElement(value, stack->top->next);
    stack->top->next = newElement;
}


char popChar(StackChar *stack)
{
    char result = stack->top->next->value;
    StackCharElement *element = stack->top->next;
    stack->top->next = stack->top->next->next;
    delete element;
    return result;
}

char topChar(StackChar *stack)
{
    return stack->top->next->value;
}

void printStackChar(StackChar *stack)
{
    StackCharElement *current = stack->top;
    while (!endOfStackChar(current))
    {
        current = current->next;
        printf("%c", current->value);
    }
}

bool endOfStackChar(StackCharElement *current)
{
    return current->next == nullptr;
}
bool isEmptyChar(StackChar *stack)
{
    return stack->top->next == nullptr;
}

void deleteStackChar(StackChar *stack)
{
    while (!isEmptyChar(stack))
        popChar(stack);
    delete stack->top;
    delete stack;
}


