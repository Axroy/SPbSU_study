#include "symbolsSumHash.h"

SymbolsSumHash::SymbolsSumHash(int tableSize) : maxSize(tableSize)
{
}

int SymbolsSumHash::hash(const QString &string)
{
    long int hash = 0;
    char symbol = '0';

    for (int i = 0; i < string.length(); i++)
    {
        symbol = string.at(i).toLatin1();
        hash += symbol;
        hash = hash % maxSize;
    }
    return abs(hash);
}
