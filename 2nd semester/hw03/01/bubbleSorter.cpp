#include "bubbleSorter.h"

BubbleSorter::BubbleSorter()
{
}

void BubbleSorter::sort(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        bool over = true;
        for (int j = 0; j < size; j++)
            if (array[i] < array[j])
            {
                swap(array, i, j);
                over = false;
            }
        if (over)
            return;
    }
}

void BubbleSorter::swap(int *array, int a, int b)
{
    int temp = array[a];
    array[a] = array[b];
    array[b] = temp;
}
