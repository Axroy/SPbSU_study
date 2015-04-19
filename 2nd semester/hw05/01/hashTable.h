#pragma once

#include <QString>
#include <cmath>
#include "list.h"

class HashTable
{
public:
    HashTable();
    HashTable(int size);
    ~HashTable();
    void addValue(QString value);
    void removeValue(QString value);
    void printTable();
    int numberOfEmptyCells();

private:
    int size;
    List **table;

    int hashFunction(QString string);
};
