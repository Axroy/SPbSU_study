#pragma once

#include "sorter.h"

///Class that uses qsort for sorting arrays
class QuickSorter : public Sorter
{
public:
    ///Constructor
    QuickSorter();
    ///Sorts an array with given size
    void sort(int *array, int size);

private:
    ///Function needed for realisation of recursive qsort algorythm; l - left edge of sorted array, r - right edge
    void recursiveSort(int *array, int l, int r);
    ///Swaps two elements with indexes a and b in an array
    void swap(int *array, int a, int b);
};
