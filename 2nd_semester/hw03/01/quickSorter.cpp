#include "quickSorter.h"

QuickSorter::QuickSorter()
{
}

void QuickSorter::sort(int *array, int size)
{
    recursiveSort(array, 0, size - 1);
}

void QuickSorter::recursiveSort(int *array, int l, int r)
{
    int i = l;
    int j = r;
    int m = (l + r) / 2;
    while (i < j)
    {
        while (array[i] < array[m])
            i++;
        while (array[j] > array[m])
            j--;
        if (i <= j)
        {
            swap(array, i, j);
            i++;
            j--;
        }
    }
    if (l < j)
        recursiveSort(array, l, j);
    if (i < r)
        recursiveSort(array, i, r);
}

void QuickSorter::swap(int *array, int a, int b)
{
    int temp = array[a];
    array[a] = array[b];
    array[b] = temp;
}
