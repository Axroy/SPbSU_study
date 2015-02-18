#include <stdio.h>
#include "stackInt.h"

struct StackElement
{
    int value;
    StackElement *next;
};


struct Stack
{
    StackElement *top;
};


StackElement *createStackElement(int value, StackElement *next)
{
    StackElement *newStackElement = new StackElement;
    newStackElement->next = next;
    newStackElement->value = value;
    return newStackElement;
}


Stack *createStack()
{
    Stack *newStack = new Stack;
    newStack->top = createStackElement(0, nullptr);
    return newStack;
}


void push(Stack *stack, int value)
{
    StackElement *newElement = createStackElement(value, stack->top->next);
    stack->top->next = newElement;
}


int pop(Stack *stack)
{
    int result = stack->top->next->value;
    StackElement *element = stack->top->next;
    stack->top->next = stack->top->next->next;
    delete element;
    return result;
}

int top(Stack *stack)
{
    return stack->top->next->value;
}

void printStack(Stack *stack)
{
    StackElement *current = stack->top;
    while (!endOfStack(current))
    {
        current = current->next;
        printf("%d", current->value);
    }
}

bool endOfStack(StackElement *current)
{
    return current->next == nullptr;
}
bool isEmpty(Stack *stack)
{
    return stack->top->next == nullptr;
}

void deleteStack(Stack *stack)
{
    while (!isEmpty(stack))
        pop(stack);
    delete stack->top;
    delete stack;
}

