#pragma once

#include "printer.h"
#include "squareArray.h"

class ConsolePrinter : public Printer
{
public:
    void print(SquareArray *array);
};
