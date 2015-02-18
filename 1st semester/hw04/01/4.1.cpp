#include <stdio.h>
#include <locale.h>

void swap(int *array, int a, int b)
{
    int temp = array[a];
    array[a] = array[b];
    array[b] = temp;
}

void quicksort(int *array, int l, int r)
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

int main()
{
    printf("Программа находит максимальный элемент массива, встречающийся более одного раза (за время, меньшее O(n^2))\n");
    printf("Введите размер массива: ");
    int size = 0;
    scanf("%d", &size);

    int *array = new int[size];
    printf("Введите элементы массива: \n");
    for (int i = 0; i < size; i++)
        scanf("%d", &array[i]);

    quicksort(array, 0, size - 1);

    int result = 0;
    int i = size - 1;
    bool hasSuchElement = false;
    while ((!hasSuchElement) && (i > 0))
    {
        if (array[i] == array[i - 1])
        {
            result = array[i];
            hasSuchElement = true;
        }
        i--;
    }

    if (hasSuchElement)
        printf("\nРезультат: %d", result);
    else
        printf("\nТакого элемента нет!");
    delete array;
    return 0;
}
