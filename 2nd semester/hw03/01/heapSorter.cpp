#include "heapSorter.h"

HeapSorter::HeapSorter()
{
}

void HeapSorter::sort(int *array, int size)
{
    for (int i = size / 2 - 1; i >= 0; i--)
        downHeap(array, i, size);

    for (int i = size - 1; i > 0; i--)
    {
         swap(array, 0, i);
         downHeap(array, 0, i);
    }
}

void HeapSorter::swap(int *array, int a, int b)
{
    int temp = array[a];
    array[a] = array[b];
    array[b] = temp;
}

void HeapSorter::downHeap(int *array, int k, int size)
{
    int maxChild = 2 * k + 1;
    while (maxChild < size)
    {
        if ((maxChild + 1 < size) && (array[maxChild] < array[maxChild + 1]))
            maxChild++;
        if (array[k] < array[maxChild])
        {
            swap(array, k, maxChild);
        }
        k = maxChild;
        maxChild = 2 * k + 1;
    }
}
