#include <iostream>
#include "hashTable.h"

HashTable::HashTable() : size(100), table(new List*[size]), hash(new HashFunctions(100))
{
    for (int i = 0; i < 100; i++)
        table[i] = new List();
}

HashTable::HashTable(int size) : size(size), table(new List*[size]), hash(new HashFunctions(size))
{
    for (int i = 0; i < size; i++)
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
    table[hash->generateHash(value)]->add(value);
}

void HashTable::removeValue(QString value)
{
    table[hash->generateHash(value)]->remove(value);
}

int HashTable::findValue(QString value)
{
    int index = hash->generateHash(value);
    if (table[index]->hasValue(value))
        return index;
    return -1;
}

void HashTable::printTable()
{
    for (int i = 0; i < size; i++)
        table[i]->print();
}

int HashTable::numberOfFilledCells()
{
    int number = 0;
    for (int i = 0; i < size; i++)
        if (!table[i]->isEmpty())
            number++;

    return number;
}

int HashTable::numberOfEmptyCells()
{
    int number = 0;
    for (int i = 0; i < size; i++)
        if (table[i]->isEmpty())
            number++;

    return number;
}

float HashTable::loadFactor()
{
    int numberOfElements = 0;
    for (int i = 0; i < size; i++)
        numberOfElements += table[i]->numberOfElements();

    return (float) numberOfElements / size;
}

int HashTable::conflictsNumber()
{
    int result = 0;
    for (int i = 0; i < size; i++)
        if (table[i]->numberOfElements() > 1)
            result++;
    return result;
}

int HashTable::maxChainLength()
{
    int max = 0;
    for (int i = 0; i < size; i++)
        if (table[i]->numberOfElements() > max)
            max = table[i]->numberOfElements();

    return max;
}

float HashTable::averageChainLength()
{
    int chainsNumber = 0;
    int totalLength = 0;
    for (int i = 0; i < size; i++)
    {
        if (table[i]->numberOfElements() > 0)
        {
            chainsNumber++;
            totalLength += table[i]->numberOfElements();
        }
    }

    return (float) totalLength / chainsNumber;
}

void HashTable::showStats()
{
    std::cout << "---------------------";
    std::cout << "\nHash table size: " << size;
    std::cout << "\nNumber of filled cells: " << numberOfFilledCells();
    std::cout << "\nNumber of empty cells: " << numberOfEmptyCells();
    std::cout << "\nLoad factor: " << loadFactor();
    std::cout << "\nNumber of conflicts (chains with length > 1): " << conflictsNumber();
    std::cout << "\nMaximum chain length: " << maxChainLength();
    std::cout << "\nAverage chain length: " << averageChainLength();
    std::cout << "\n---------------------";
}

void HashTable::changeHashFunction(Functions newFunction)
{
    hash->changeFunction(newFunction);
}

