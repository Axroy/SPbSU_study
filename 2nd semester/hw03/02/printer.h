#pragma once

#include "squareArray.h"

///A base class for different printers of arrays
class Printer
{
public:
    ///Prints a square array
    virtual void print(SquareArray *array) = 0;
};

