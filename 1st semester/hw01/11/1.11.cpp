#include <stdio.h>

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
    printf("ѕрограмма сортирует массив, использу€ алгоритм быстрой сортировки\n");
    printf("¬ведите длину массива: ");
    int sizeA = 0;
    scanf("%d", &sizeA);
    sizeA--;
    printf("¬ведите элементы массива:\n");
    int array[sizeA];
    for (int i = 0; i <= sizeA; i++)
        scanf("%d", &array[i]);

    quicksort(array, 0, sizeA);

    for (int i = 0; i <= sizeA; i++)
        printf("%d ", array[i]);
    return 0;
}
