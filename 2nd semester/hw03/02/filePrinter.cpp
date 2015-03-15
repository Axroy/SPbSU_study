#include <fstream>
#include "filePrinter.h"


void FilePrinter::openFile(char *fileName)
{
    file.open(fileName);
}

void FilePrinter::closeFile()
{
    file.close();
}

void FilePrinter::out(int number)
{
    file << number << " ";
}
