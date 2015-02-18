#include <stdio.h>
#include <locale.h>
#include "stackChar.h"
#include "calculator.h"

int main()
{
    setlocale(LC_ALL, "rus");
    printf("Программа преобразует выражение из инфиксной записи в постфиксную.");
    printf("\nВведите выражение (оно должно завершаться точкой): ");
    const int size = 100;
    char string[size] = "";
    fgets(string, size, stdin);
    char resultingString[size] = "";

    StackChar *stack = createStackChar();

    convertToPostfix(stack, string, resultingString);

    printf("\n\n");

    int j = 0;
    while (resultingString[j] != '.')
    {
        printf("%c", resultingString[j]);
        j++;
    }

    deleteStackChar(stack);
    return 0;
}
