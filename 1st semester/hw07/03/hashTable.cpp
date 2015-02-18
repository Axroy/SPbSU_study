#include <stdio.h>
#include <math.h>
#include "list.h"
#include "line.h"

const int hashTableSize = 10000;

struct HashTable
{
    List *table[hashTableSize];
};


int hashFunction(Line *line)
{
    int hash = 0;
    int i = 0;
    char symbol = '0';

    while (symbol != '\0')
    {
        symbol = getSymbol(line, i);
        hash += pow(3, i) * symbol;
        hash = hash % hashTableSize;
        i++;
    }

    return abs(hash);

}


HashTable *createTable()
{
    HashTable *newTable = new HashTable;

    for (int i = 0; i < hashTableSize; i++)
        newTable->table[i] = createList();

    return newTable;
}


void addLine(HashTable *table, Line *line)
{
    if (!isEmpty(line))
        insertSorted(table->table[hashFunction(line)], line);
}


void printListInTable(HashTable *table, int position)
{
    printList(table->table[position]);
}


void printHashTable(HashTable *table)
{
    for (int i = 0; i < hashTableSize; i++)
        printList(table->table[i]);
}


float loadFactor(HashTable *table)
{
    int elementsNumber = 0;
    for (int i = 0; i < hashTableSize; i++)
        elementsNumber += numberOfElements(table->table[i]);

    return (float) elementsNumber / hashTableSize;
}


float averageChainLength(HashTable *table)
{
    int chainsNumber = 0;
    int totalLength = 0;
    for (int i = 0; i < hashTableSize; i++)
    {
        if (numberOfElements(table->table[i]) > 0)
        {
            chainsNumber++;
            totalLength += numberOfElements(table->table[i]);
        }
    }

    return (float) totalLength / chainsNumber;
}


int maxChainLength(HashTable *table)
{
    int max = 0;
    for (int i = 0; i < hashTableSize; i++)
        if (numberOfElements(table->table[i]) > max)
            max = numberOfElements(table->table[i]);

    return max;
}


Line *maxChainLengthElements(HashTable *table)
{
    int max = 0;
    for (int i = 0; i < hashTableSize; i++)
        if (numberOfElements(table->table[i]) > max)
            max = i;

    return differentElements(table->table[max]);
}


void printNumberOfEachWord(HashTable *table)
{
    for (int i = 0; i < hashTableSize; i++)
    {
        if (!isEmpty(table->table[i]))
            printDifferentElementsWithNumbers(table->table[i]);
    }
}


int totalNumberOfElements(HashTable *table)
{
    int number = 0;
    for (int i = 0; i < hashTableSize; i++)
        number += numberOfElements(table->table[i]);

    return number;
}


int numberOfEmptyCells(HashTable *table)
{
    int number = 0;
    for (int i = 0; i < hashTableSize; i++)
        if (isEmpty(table->table[i]))
            number++;

    return number;
}


void deleteTable(HashTable *table)
{
    for (int i = 0; i < hashTableSize; i++)
        deleteList(table->table[i]);
    delete[] table;
}
