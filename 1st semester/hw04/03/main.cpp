#include <stdio.h>
#include <locale.h>
#include "stackInt.h"
#include "calculator.h"

int main()
{
    setlocale(LC_ALL, "rus");
    printf("Программа считает выражение в постфиксной записи.");
    printf("\nВведите выражение (оно должно завершаться точкой): ");
    const int size = 1000;
    char string[size] = "";
    fgets(string, size, stdin);

    Stack *stack = createStack();

    int result = postfixCount(stack, string);
    printf("Результат: %d", result);

    deleteStack(stack);
    return 0;
}
