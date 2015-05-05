#include "polynomialHash.h"

PolynomialHash::PolynomialHash(int tableSize) : maxSize(tableSize)
{
}

int PolynomialHash::hash(const QString &string)
{
    long int hash = 0;
    char symbol = '0';

    for (int i = 0; i < string.length(); i++)
    {
        symbol = string.at(i).toLatin1();
        hash += pow(3, i) * symbol;
        hash = hash % maxSize;
    }
    return abs(hash);
}
