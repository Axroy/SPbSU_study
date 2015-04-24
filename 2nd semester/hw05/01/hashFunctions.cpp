#include "hashFunctions.h"

HashFunctions::HashFunctions() : current(polynomial), tableSize(100)
{
}

HashFunctions::HashFunctions(int size) : current(polynomial), tableSize(size)
{
}

int HashFunctions::generateHash(QString string)
{
    switch (current)
    {
        case polynomial:
            return polynomialHash(string);
            break;

        case symbolsSum:
            return sumHash(string);
            break;
    }
    return -1;
}

void HashFunctions::changeFunction(Functions newFunction)
{
    current = newFunction;
}

int HashFunctions::polynomialHash(QString string)
{
    int hash = 0;
    char symbol = '0';

    for (int i = 0; i < string.length(); i++)
    {
        symbol = string.at(i).toLatin1();
        hash += pow(3, i) * symbol;
        hash = hash % tableSize;
    }
    return hash;
}

int HashFunctions::sumHash(QString string)
{
    int hash = 0;
    char symbol = '0';

    for (int i = 0; i < string.length(); i++)
    {
        symbol = string.at(i).toLatin1();
        hash += symbol;
        hash = hash % tableSize;
    }
    return hash;
}
