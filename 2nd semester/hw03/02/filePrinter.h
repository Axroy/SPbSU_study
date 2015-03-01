#pragma once

#include "printer.h"

class FilePrinter : public Printer
{
public:
    FilePrinter(char *newFileName);
    void print(SquareArray *array);

private:
    char *fileName;
};

