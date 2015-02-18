#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "locale.h"

int sizeOfNumber(int num)
{
    int counter = 0;
    if (num == 0)
        return 1;
    else
    {
        while (num != 0)
        {
            counter++;
            num = num / 10;
        }
    }
    return counter;
}

void fillArrayWithNumber(int *array, int size, int num)
{
    for (int i = size - 1; i >= 0; i--)
    {
        array[i] = num % 10;
        num = num / 10;
    }
}

void swap(int array[], int a, int b)
{
    int temp = array[a];
    array[a] = array[b];
    array[b] = temp;
}

void quicksort(int array[], int l, int r)
{
    int i = l;
    int j = r;
    int m = (l + r) / 2;
    while (i < j)
    {
        while ((i < j) && (array[i] < array[m]))
            i++;
        while ((i < j) && (array[j] > array[m]))
            j--;
        swap(array, i, j);
        i++;
        j--;
    }
    if (l < j)
        quicksort(array, l, j);
    if (i < r)
        quicksort(array, i, r);
}

main()
{
    setlocale(LC_ALL, "rus");
    srand(time(0));
    printf("Программа переставляет цифры натурального числа так, чтобы образовалось наименьшее число, записанное этими же цифрами\n");
    printf("Введите число: ");
    int number = 0;
    scanf("%d", &number);

    int size = 0;
    size = sizeOfNumber(number);

    int *arrayOfNumber = new int[size];
    fillArrayWithNumber(arrayOfNumber, size, number);

    quicksort(arrayOfNumber, 0, size - 1);

    if (arrayOfNumber[0] == 0)
    {
        int min = 0;
        int i = 0;
        while (min == 0)
        {
            i++;
            if (arrayOfNumber[i] > min)
                min = arrayOfNumber[i];
        }
        swap(arrayOfNumber, 0, i);
    }

    for (int i = 0; i < size; i++)
        printf("%d", arrayOfNumber[i]);

    delete arrayOfNumber;
    return 0;
}
