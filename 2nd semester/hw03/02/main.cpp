#include <iostream>
#include "squareArray.h"

int main()
{
    const int size = 4;
    SquareArray *array = new SquareArray(size);
    array->print();
    delete array;

    return 0;
}

