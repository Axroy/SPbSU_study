#include <stdio.h>

main()
{
    printf("Программа проверяет, является ли строка (длиной 10 символов) палиндромом\n");
    const int size = 10;
    char string[size];
    printf("Введите строку:\n");
    scanf("%s", &string);

    bool isPalindrome = true;
    for (int i = 0; i <= size/2; i++)
        if (string[i] != string[size - (i + 1)])
            isPalindrome = false;

    if (isPalindrome)
        printf("Является");
    else
        printf("Не является");
    return 0;
}
