#ifndef STACKCHAR_H
#define STACKCHAR_H

struct StackCharElement;

struct StackChar;

StackCharElement *createStackCharElement(char value, StackCharElement *next);
StackChar *createStackChar();
void pushChar(StackChar *stack, char value);
char popChar(StackChar *stack);
char topChar(StackChar *stack);
void printStackChar(StackChar *stack);
bool endOfStackChar(StackCharElement *current);
void deleteStackChar(StackChar *stack);
bool isEmptyChar(StackChar *stack);

#endif // STACKCHAR_H
