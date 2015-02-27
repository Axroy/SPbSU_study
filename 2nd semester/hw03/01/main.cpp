#include <iostream>
#include "sorter.h"
#include "quickSorter.h"
#include "heapSorter.h"
#include "insertionSorter.h"
#include "bubbleSorter.h"

///Prints an array with known size
void print(int *array, int size)
{
    for (int i = 0; i < size; i++)
        std::cout << array[i] << " ";
}

int main()
{
    std::cout << "The program sorts an araay with different sorting algorythms.\n";
    const int size = 10;
    int array[size] = {1, 12, 5, 26, 7, 14, 3, 7, 2};

    std::cout << "Original array: \n";
    print(array, size);




    std::cout << "\n\nQuick sort: \n";

    Sorter *quick = new QuickSorter;
    quick->sort(array, size);

    print(array, size);




    std::cout << "\n\nHeap sort:\n";

    Sorter *heap = new HeapSorter;
    heap->sort(array, size);

    print(array, size);




    std::cout << "\n\nInsertion sort:\n";

    Sorter *insertion = new InsertionSorter;
    insertion->sort(array, size);

    print(array, size);




    std::cout << "\n\nBubble sort:\n";

    Sorter *bubble = new BubbleSorter;
    bubble->sort(array, size);

    print(array, size);

    return 0;
}

