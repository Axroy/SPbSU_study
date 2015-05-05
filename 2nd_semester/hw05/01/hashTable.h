#pragma once

#include <QString>
#include <cmath>
#include "list.h"
#include "hashFunctions.h"
#include "polynomialHash.h"
#include "symbolsSumHash.h"

enum HashType
{
    polynomial,
    symbolsSum
};


///Class resembling hash table.
class HashTable
{
public:
    HashTable();
    HashTable(int size);
    HashTable(int size, HashType hashType);
    ~HashTable();

    ///Adds some string value to the table.
    void addValue(QString value);
    ///Removes some string value from the table.
    void removeValue(QString value);
    ///Returns position of some string value in the table. Returns -1 if can't find the value.
    int findValue(QString value);
    ///Prints all non-empty cells of the table.
    void printTable();
    ///Returns number of filled cells.
    int numberOfFilledCells();
    ///Returns number of empty cells.
    int numberOfEmptyCells();
    ///Prints to console number of filled, empty cells, load factor, number of conflicts, max and average chain length.
    void showStats();
    ///Changes hash function to one from HashFunctions class.
    void changeHashFunction(HashType hashType);

private:
    int size;
    List **table;
    HashFunctions *hashFunction;

    float loadFactor();
    int conflictsNumber();
    int maxChainLength();
    float averageChainLength();
};
