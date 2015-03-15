#pragma once

#include "printer.h"
#include "squareArray.h"

///A class for printing square arrays spiral-like to console
class ConsolePrinter : public Printer
{
private:
    void out(int number);
};
