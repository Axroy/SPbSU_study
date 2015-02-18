#ifndef CALCULATOR_H
#define CALCULATOR_H

int operationPriority(char operation);
void convertToPostfix(StackChar *stack, char *string, char *resultingString);

#endif // CALCULATOR_H
