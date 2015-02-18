#include <stdio.h>

void printRepresentation(int arrayOfSum[], int pointer)
{
    printf("\n");
        for (int i = 0; i < pointer; i++)
            if (i != pointer - 1)
                printf("%d + ", arrayOfSum[i]);
            else
                printf("%d", arrayOfSum[i]);
}

void representAsSum(int x, int sum, int arrayOfSum[], int pointer)
{
    if (sum == 0)
        printRepresentation(arrayOfSum, pointer);
    else
        for (int i = x; i <= sum; i++)
        {
            arrayOfSum[pointer] = i;
            pointer++;
            representAsSum(i, sum - i, arrayOfSum, pointer);
            pointer--;
        }
}

main()
{
    printf("Программа печатает все представления натурального числа n суммой натуральных слагаемых\n");
    printf("Введите n: ");
    int n = 0;
    scanf("%d", &n);

    const int size = 100;
    int array[size];
    int p = 0;
    representAsSum(1, n, array, p);

    return 0;
}
