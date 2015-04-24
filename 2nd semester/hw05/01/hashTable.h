#pragma once

#include <QString>
#include <cmath>
#include "list.h"
#include "hashFunctions.h"

class HashTable
{
public:
    HashTable();
    HashTable(int size);
    ~HashTable();
    void addValue(QString value);
    void removeValue(QString value);
    int findValue(QString value);
    void printTable();
    int numberOfFilledCells();
    int numberOfEmptyCells();
    float loadFactor();
    int conflictsNumber();
    int maxChainLength();
    float averageChainLength();
    void showStats();
    void changeHashFunction(Functions newFunction);

private:
    int size;
    List **table;
    HashFunctions *hash;
};
