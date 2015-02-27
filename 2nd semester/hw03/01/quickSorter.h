#pragma once

#include "sorter.h"

class QuickSorter : public Sorter
{
public:
    QuickSorter();
    void sort(int *array, int size);

private:
    void recursiveSort(int *array, int l, int r);
    void swap(int *array, int a, int b);
};
