#pragma once

#include <QString>

///Enumerable for easy access to different hash function types.
enum Functions
{
    polynomial,
    symbolsSum
};

///Class for handling different hash functions.
class HashFunctions
{
public:
    HashFunctions();
    ///Recieves hash table size.
    HashFunctions(int size);

    ///Generates hash from string depending on current hash function.
    int generateHash(QString string);

    ///Changes current hash function to one from enumerable.
    void changeFunction(Functions newFunction);

private:
    Functions current;
    int tableSize;

    int polynomialHash(QString string);
    int sumHash(QString string);
};

