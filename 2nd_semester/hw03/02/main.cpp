#include <iostream>
#include "filePrinterTests.h"
#include "squareArray.h"
#include "consolePrinter.h"
#include "filePrinter.h"

int main()
{
    FilePrinterTests tests;
    QTest::qExec(&tests);

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

    std::cout << "Would you like to print your spiral to the console or to a file?\n";
    std::cout << "(enter 'c' or 'f'): ";

    char command = '0';
    std::cin >> command;

    if (command == 'c')
    {
        std::cout << "\n";
        ConsolePrinter consolePrinter;
        consolePrinter.print(array);
    }
    else if (command == 'f')
    {
        std::cout << "Enter file name: ";
        const int maxLength = 100;
        char fileName[maxLength] = "";
        std::cin >> fileName;

        FilePrinter filePrinter;
        filePrinter.openFile(fileName);
        filePrinter.print(array);
        filePrinter.closeFile();
        std::cout << "Array printed to file '" << fileName << "'!";
    }
    else
    {
        std::cout << "Wrong command!";
    }


    delete array;
    return 0;
}

