#pragma once

#include "sorter.h"

class HeapSorter : public Sorter
{
public:
    HeapSorter();
    void sort(int *array, int size);

private:
    void swap(int *array, int a, int b);
    void downHeap(int *array, int k, int size);
};

