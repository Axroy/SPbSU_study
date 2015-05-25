#pragma once

#include "hashFunctions.h"

///Class that generates hash as sum of codes of symbols in input string.
class SymbolsSumHash : public HashFunctions
{
public:
    ///Gets max size of hash table (and thus max hash number).
    SymbolsSumHash(int tableSize);
    ///Generates hash number.
    int hash(const QString &string);

private:
    int maxSize;
};

