#include <iostream>
#include "printer.h"


void Printer::print(SquareArray *array)
{
    int size = array->getSize();
    int i = size / 2;
    int j = size / 2;
    int counter = 0;
    out(array->element(i, j));

    while (counter != size - 1)
    {
        counter++;
        if (counter % 2 == 1)
        {
            for (int k = 0; k < counter; k++)
            {
                j++;
                out(array->element(i, j));
            }
            for (int k = 0; k < counter; k++)
            {
                i--;
                out(array->element(i, j));
            }
        }
        else
        {
            for (int k = 0; k < counter; k++)
            {
                j--;
                out(array->element(i, j));
            }
            for (int k = 0; k < counter; k++)
            {
                i++;
                out(array->element(i, j));
            }
        }
    }
    for (j = 1; j < size; j++)
        out(array->element(i, j));
}
