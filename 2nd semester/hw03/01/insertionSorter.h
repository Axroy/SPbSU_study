#pragma once

#include "sorter.h"

///Class that uses insertion sort for sorting arrays
class InsertionSorter : public Sorter
{
public:
    ///Constructor
    InsertionSorter();
    ///Sorts an array with given size
    void sort(int *array, int size);
};

