#include "hashTable.h"

HashTable::HashTable() : size(100), table(new List*[size])
{
    for (int i = 0; i < 100; i++)
        table[i] = new List;
}

HashTable::HashTable(int size) : size(size), table(new List*[size])
{
    for (int i = 0; i < 100; i++)
        table[i] = new List;
}

HashTable::~HashTable()
{
    for (int i = 0; i < size; i++)
        delete table[i];
    delete[] table;
}

/*void HashTable::addValue(QString string)
{
    table[hashFunction(string)] << string;
}

int HashTable::hashFunction(QString string)
{
    int hash = 0;
    int i = 0;
    char symbol = '0';

    while (symbol != '\0')
    {
        symbol = string[i];
        //symbol = getSymbol(line, i);
        hash += pow(3, i) * symbol;
        hash = hash % size;
        i++;
    }

    return abs(hash);
}*/

