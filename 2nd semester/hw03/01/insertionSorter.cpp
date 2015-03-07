#include "insertionSorter.h"

InsertionSorter::InsertionSorter()
{
}

void InsertionSorter::sort(int *array, int size)
{
    for (int i = 1; i < size; i++)
    {
        int j = i;
        while (j > 0 && array[j - 1] > array[j])
        {
            int tmp = array[j];
            array[j] = array[j - 1];
            array[j - 1] = tmp;
            j--;
        }
    }
}
