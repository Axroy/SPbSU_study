#include <stdio.h>

int power(int x, int k)
{
    int p = 1;
    while (k > 0)
    {
        if ((k % 2) == 1)
            p = p * x;
        x = x * x;
        k = k / 2;
    }
    return p;
}

main()
{
    printf("Программа возводит число в целую степень");
    printf("\nВведите число: ");
    int a = 0;
    scanf("%d", &a);
    printf("Введите степень: ");
    int n = 0;
    scanf("%d", &n);

    int res = power(a, n);
    printf("\nРезультат: %d", res);
}
