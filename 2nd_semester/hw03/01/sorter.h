#pragma once

///Base class for different sorting algorythms
class Sorter
{
public:
    ///Sorts an array with given size
    virtual void sort(int *array, int size) = 0;
};

