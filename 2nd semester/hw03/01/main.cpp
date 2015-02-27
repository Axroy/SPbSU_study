#include <iostream>
#include "sorter.h"
#include "quickSorter.h"

int main()
{
    const int size = 10;
    int array[size] = {1, 12, 5, 26, 7, 14, 3, 7, 2};

    QuickSorter quick;
    quick.sort(array, size);

    for (int i = 0; i < size; i++)
        std::cout << array[i] << " ";
    return 0;
}

