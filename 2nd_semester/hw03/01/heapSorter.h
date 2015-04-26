#pragma once

#include "sorter.h"

///Class that uses heap sort for sorting arrays
class HeapSorter : public Sorter
{
public:
    ///Constructor
    HeapSorter();
    ///Sorts an array with given size
    void sort(int *array, int size);

private:
    ///Swaps two elements with indexes a and b in an array
    void swap(int *array, int a, int b);
    ///Reorders the array starting with element k in the way needed for heap sort
    void downHeap(int *array, int k, int size);
};

