#include <iostream>
#include "squareArray.h"
//#include "printer.h"
#include "consolePrinter.h"

int main()
{
    std::cout << "The program shows elements of a square array going spiral-like from it's center.";
    std::cout << "So, its size must be an odd number.\n";
    std::cout << "Enter the array's size: ";
    int size = 0;
    std::cin >> size;
    if (size % 2 == 0)
    {
        std::cout << "It's an even number!";
        return -1;
    }

    SquareArray *array = new SquareArray(size);
    std::cout << "Original array (randomly generated): \n";
    array->print();

    std::cout << "Would you like to print your spiral to console or to a file?\n";
    std::cout << "(enter 'c' or 'f'): ";

    char command = '0';
    std::cin >> command;

    if (command == 'c')
    {
        std::cout << "\n";
        Printer *printer = new ConsolePrinter;
        printer->print(array);
    }


    delete array;
    return 0;
}

