#include <stdio.h>

void swap(int arr[], int a, int b)
{
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void downHeap(int arr[], int k, int sizeA)
{
    int maxChild = 2 * k + 1;
    while (maxChild < sizeA)
    {
        if ((maxChild + 1 < sizeA) && (arr[maxChild] < arr[maxChild + 1]))
            maxChild++;
        if (arr[k] < arr[maxChild])
        {
            swap(arr, k, maxChild);
        }
        k = maxChild;
        maxChild = 2 * k + 1;
    }
}
void heapsort(int arr[], int sizeA)
{
    for (int i = sizeA / 2 - 1; i >= 0; i--)
        downHeap(arr, i, sizeA);

    for (int i = sizeA - 1; i > 0; i--)
    {
         swap(arr, 0, i);
         downHeap(arr, 0, i);
    }

}
main()
{
    printf("Программа реализует алгоритм пирамидальной сортировки");
    const int size = 10;
    int array[size];
    printf("\nВведите элементы массива (%d штук):\n", size);
    for (int i = 0; i < size; i++)
        scanf("%d", &array[i]);

    heapsort(array, size);

    for (int i = 0; i < size; i++)
        printf("%d ", array[i]);
    return 0;
}
