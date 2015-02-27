#pragma once

#include "sorter.h"

///Class that uses bubble sort for sorting arrays
class BubbleSorter : public Sorter
{
public:
   ///Constructor
   BubbleSorter();
   ///Sorts an array with given size
   void sort(int *array, int size);

private:
   ///Swaps two elements with indexes a and b in an array
   void swap(int *array, int a, int b);
};

