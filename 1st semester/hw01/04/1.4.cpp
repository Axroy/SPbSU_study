#include <stdio.h>

main()
{
    const int maxSum = 27;
    printf("Программа находит количество счастливых билетов\n");
    int arr[maxSum + 1];
    for (int i = 0; i <= maxSum; i++)
        arr[i] = 0;

    int sum = 0;
    for (int i = 0; i <= 9; i++)
        for (int j = 0; j <= 9; j++)
            for (int k = 0; k <= 9; k++)
            {
                sum = i + j + k;
                arr[sum]++;
            }

    int res = 0;
    for (int i = 0; i <= maxSum; i++)
        res = res + arr[i] * arr[i];
    printf("\nРезультат: %d", res);
    return 0;
}
