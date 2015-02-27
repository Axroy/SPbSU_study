#pragma once

#include "sorter.h"

class InsertionSorter : public Sorter
{
public:
    InsertionSorter();
    void sort(int *array, int size);
};

