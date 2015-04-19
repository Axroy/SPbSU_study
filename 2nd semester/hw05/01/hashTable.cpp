#include <iostream>
#include "hashTable.h"

HashTable::HashTable() : size(100), table(new List*[size])
{
    for (int i = 0; i < 100; i++)
        table[i] = new List();
}

HashTable::HashTable(int size) : size(size), table(new List*[size])
{
    for (int i = 0; i < 100; i++)
        table[i] = new List();
}

HashTable::~HashTable()
{
    for (int i = 0; i < size; i++)
        delete table[i];
    delete[] table;
}

void HashTable::addValue(QString value)
{
    table[hashFunction(value)]->add(value);
}

void HashTable::removeValue(QString value)
{
    table[hashFunction(value)]->remove(value);
}

void HashTable::printTable()
{
    for (int i = 0; i < size; i++)
        table[i]->print();
}

int HashTable::numberOfEmptyCells()
{
    int number = 0;
    for (int i = 0; i < size; i++)
        if (table[i]->isEmpty())
            number++;

    return number;
}

int HashTable::hashFunction(QString string)
{
    int hash = 0;
    char symbol = '0';

    for (int i = 0; i < string.size(); i++)
    {
        symbol = string.at(i).toLatin1();
        hash += pow(3, i) * symbol;
        hash = hash % size;
    }

    return abs(hash);
}

