#include <iostream>
#include "consolePrinter.h"

void ConsolePrinter::print(SquareArray *array)
{
    int size = array->getSize();
    int i = size / 2;
    int j = size / 2;
    int counter = 0;
    std::cout << array->element(i, j) << " ";

    while (counter != size - 1)
    {
        counter++;
        if (counter % 2 == 1)
        {
            for (int k = 0; k < counter; k++)
            {
                j++;
                std::cout << array->element(i, j) << " ";
            }
            for (int k = 0; k < counter; k++)
            {
                i--;
                std::cout << array->element(i, j) << " ";
            }
        }
        else
        {
            for (int k = 0; k < counter; k++)
            {
                j--;
                std::cout << array->element(i, j) << " ";
            }
            for (int k = 0; k < counter; k++)
            {
                i++;
                std::cout << array->element(i, j) << " ";
            }
        }
    }
    for (j = 1; j < size; j++)
        std::cout << array->element(i, j) << " ";
}
