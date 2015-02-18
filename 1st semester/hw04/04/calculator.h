#ifndef CALCULATOR_H
#define CALCULATOR_H

int operationPriority(char operation);
void convertToPostfix(StackChar *stack, char *string, char *resultingString);
int count(int a, int b, char operation);
int postfixCount(Stack *stack, char *string);

#endif // CALCULATOR_H
