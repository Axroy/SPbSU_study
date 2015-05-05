#pragma once

#include "hashFunctions.h"

///Class that generates hash using polynomial expression of input string.
class PolynomialHash : public HashFunctions
{
public:
    ///Gets max size of hash table (and thus max hash number).
    PolynomialHash(int tableSize);
    ///Generates hash number.
    int hash(const QString &string);

private:
    int maxSize;
};

