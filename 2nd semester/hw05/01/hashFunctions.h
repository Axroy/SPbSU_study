#pragma once

#include <QString>

enum Functions
{
    polynomial,
    symbolsSum
};

class HashFunctions
{
public:
    HashFunctions();
    HashFunctions(int size);

    int generateHash(QString string);
    void changeFunction(Functions newFunction);

private:
    Functions current;
    int tableSize;

    int polynomialHash(QString string);
    int sumHash(QString string);
};

