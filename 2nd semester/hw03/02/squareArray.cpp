#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "squareArray.h"

SquareArray::SquareArray() : size(5)
{
    array = new int *[size];
    for (int i = 0; i < size; i++)
        array[i] = new int[size];
}

SquareArray::SquareArray(int arraySize)
{
    array = new int *[arraySize];
    for (int i = 0; i < arraySize; i++)
        array[i] = new int[arraySize];

    srand(time(0));
    for (int i = 0; i < arraySize; i++)
        for (int j = 0; j < arraySize; j++)
            array[i][j] = rand()%10;

    size = arraySize;
}

SquareArray::~SquareArray()
{
    for (int i = 0; i < size; i++)
        delete[] array[i];
    delete[] array;
}

void SquareArray::print()
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
            std::cout << array[i][j] << " ";
        std::cout << "\n";
    }
}

int SquareArray::getSize()
{
    return size;
}
