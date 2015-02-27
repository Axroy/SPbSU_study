#pragma once

#include "sorter.h"

class BubbleSorter : public Sorter
{
public:
    BubbleSorter();
   void sort(int *array, int size);

private:
   void swap(int *array, int a, int b);
};

