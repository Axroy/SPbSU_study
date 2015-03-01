#pragma once

#include "printer.h"
#include "squareArray.h"

///A class for printing square arrays spiral-like to console
class ConsolePrinter : public Printer
{
public:
    ///Prints square array spiral-like
    void print(SquareArray *array);
};
