#include <stdio.h>

int factR(int x);
int factI(int x);

main()
{
    printf("Программа вычисляет факториал числа двумя способами: рекурсивно и итеративно\n");
    printf("Введите число: ");
    int n = 0;
    scanf("%d", &n);

    int resR = factR(n);
    int resI = factI(n);

    printf("\nРезультаты: %d и %d", resR, resI);
    printf("\nДа, они одинаковые");
    return 0;
}

int factR(int x)
{
    if (x < 0)
        return 0;
    if (x == 0)
        return 1;
    else
        return x * factR(x - 1);
}

int factI(int x)
{
    if (x < 0)
        return 0;
    if (x == 0)
        return 1;
    else
    {
        int y = 1;
        for (int i = 1; i <= x; i++)
            y = y * i;
        return y;
    }
}
