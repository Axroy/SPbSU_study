#pragma once

#include <QString>

enum functions
{
    polynomial,
    sumOfLetters
};

class HashFunctions
{
public:
    HashFunctions();
    HashFunctions(int size);

    int generateHash(QString string);
    void changeFunction(functions newFunction);

private:
    functions current;
    int tableSize;

    int polynomialHash(QString string);
    int sumHash(QString string);
};

