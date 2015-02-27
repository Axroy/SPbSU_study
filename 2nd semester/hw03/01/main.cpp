#include <iostream>
#include "sorter.h"
#include "quickSorter.h"
#include "heapSorter.h"
#include "insertionSorter.h"
#include "bubbleSorter.h"

void print(int *array, int size)
{
    for (int i = 0; i < size; i++)
        std::cout << array[i] << " ";
}

int main()
{
    const int size = 10;
    int array[size] = {1, 12, 5, 26, 7, 14, 3, 7, 2};

    std::cout << "Original array: \n\n";
    print(array, size);




    std::cout << "\n\nQuick sort: \n\n";

    QuickSorter quick;
    quick.sort(array, size);

    print(array, size);




    std::cout << "\n\nHeap sort:\n\n";

    HeapSorter heap;
    heap.sort(array, size);

    print(array, size);




    std::cout << "\n\nInsertion sort: \n\n";

    InsertionSorter insertion;
    insertion.sort(array, size);

    print(array, size);




    std::cout << "\n\nBubble sort: \n\n";

    BubbleSorter bubble;
    bubble.sort(array, size);

    print(array, size);

    return 0;
}

