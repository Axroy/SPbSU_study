#pragma once

#include <fstream>
#include "printer.h"

///A class for printing square arrays spiral-like to file
class FilePrinter : public Printer
{
public:
    ///Opens file with manual name
    void openFile(char *fileName);
    ///Closes previously opened file
    void closeFile();

private:
    void out(int number);

    std::ofstream file;
};

