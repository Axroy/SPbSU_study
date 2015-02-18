#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "locale.h"

void showArray(int **array, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\n");
        for (int j = 0; j < n; j++)
            printf("%d ", array[i][j]);
    }
}

void showArraySpiral(int **array, int n)
{
    printf("\n\n");
    int i = n / 2;
    int j = n / 2;
    int counter = 0;
    printf("%d ", array[i][j]);

    while (counter != n - 1)
    {
        counter++;
        if (counter % 2 == 1)
        {
            for (int k = 0; k < counter; k++)
            {
                j++;
                printf("%d ", array[i][j]);
            }
            for (int k = 0; k < counter; k++)
            {
                i--;
                printf("%d ", array[i][j]);
            }
        }
        else
        {
            for (int k = 0; k < counter; k++)
            {
                j--;
                printf("%d ", array[i][j]);
            }
            for (int k = 0; k < counter; k++)
            {
                i++;
                printf("%d ", array[i][j]);
            }
        }
    }
    for (j = 1; j < n; j++)
        printf("%d ", array[i][j]);
}

main()
{
    setlocale(LC_ALL, "rus");
    srand(time(0));
    printf("Программа выводит элементы двумерного массива размерностью n x n при обходе его по спирали, начиная с центра.\n");
    printf("Размер массива (n) - нечетное число!\n");
    printf("Введите размер массива (n): ");
    int size = 0;
    scanf("%d", &size);
    if (size % 2 == 0)
        while (size % 2 == 0)
        {
            printf("\nВведите нечетное число!: ");
            scanf("%d", &size);
        }

    int **array = new int *[size];
    for (int i = 0; i < size; i++)
        array[i] = new int[size];

    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            array[i][j] = rand()%10;

    showArray(array, size);
    showArraySpiral(array, size);

    return 0;
}
