#include <stdio.h>

main()
{
    printf("Программа выясняет, верно ли расставлены скобки в строке\n");
    printf("Введите длину строки: ");
    int size = 0;
    scanf("%d", &size);
    printf("Введите строку, содержащую скобки:\n");
    char string[size];
    int i = 0;
    for (i = 0; i <= size; i++)
        scanf ("%c", &string[i]);

    bool isRight = true;
    int k = 0;
    for (i = 0; i <= size; i++)
    {
        if (string[i] == '(')
            k++;
        if (string[i] == ')')
            k--;
        if (k < 0)
            isRight = false;
    }
    if (isRight)
        printf ("правильно");
    else
        printf ("ошибка");
    return 0;
}



