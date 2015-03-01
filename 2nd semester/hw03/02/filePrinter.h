#pragma once

#include "printer.h"

///A class for printing square arrays spiral-like to file
class FilePrinter : public Printer
{
public:
    ///Constructor with manual name of file
    FilePrinter(char *newFileName);
    ///Prints square array spiral-like
    void print(SquareArray *array);

private:
    char *fileName;
};

