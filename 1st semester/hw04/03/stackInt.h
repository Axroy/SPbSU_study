#ifndef STACKINT_H
#define STACKINT_H

struct StackElement;
struct Stack;

StackElement *createStackElement(int value, StackElement *next);
Stack *createStack();
void push(Stack *stack, int value);
int pop(Stack *stack);
int top(Stack *stack);
void printStack(Stack *stack);
bool endOfStack(StackElement *current);
void deleteStack(Stack *stack);
bool isEmpty(Stack *stack);

#endif // STACKINT_H
