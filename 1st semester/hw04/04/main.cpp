#include <stdio.h>
#include <locale.h>
#include "stackChar.h"
#include "stackInt.h"
#include "calculator.h"

int main()
{
    setlocale(LC_ALL, "rus");
    printf("Программа находит значение выражения.");
    printf("\nВведите выражение (оно должно завершаться точкой): ");
    const int size = 1000;
    char string[size] = "";
    char postfixString[size] = "";
    fgets(string, size, stdin);

    StackChar *convertingStack = createStackChar();
    convertToPostfix(convertingStack, string, postfixString);
    deleteStackChar(convertingStack);

    Stack *countingStack = createStack();
    int result = postfixCount(countingStack, postfixString);
    deleteStack(countingStack);

    printf("Результат: %d", result);

    return 0;
}
