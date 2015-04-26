#pragma once

#include "squareArray.h"

///A base class for different printers of arrays
class Printer
{
public:
    ///Prints a square array
    void print(SquareArray *array);

private:
    virtual void out(int number) = 0;
};

