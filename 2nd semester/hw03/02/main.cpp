#include <iostream>
#include "squareArray.h"

int main()
{
    std::cout << "The program shows elements of a square array going spiral-like from it's center.";
    std::cout << "So, its size must be an even number.\n";
    std::cout << "Enter the array's size: ";
    int size = 0;
    std::cin >> size;
    if (size % 2 != 0)
    {
        std::cout << "It's an odd number!";
        return -1;
    }

    SquareArray *array = new SquareArray(size);
    array->print();
    delete array;

    return 0;
}

