#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "line.h"

struct HashTable;

int hashFunction(Line *line);
HashTable *createTable();
void addLine(HashTable *table, Line *line);
void addLineSingle(HashTable *table, Line *line);
void printListInTable(HashTable *table, int position);
void printHashTable(HashTable *table);
float loadFactor(HashTable *table);
float averageChainLength(HashTable *table);
int maxChainLength(HashTable *table);
Line *maxChainLengthElements(HashTable *table);
void printNumberOfEachWord(HashTable *table);
int totalNumberOfElements(HashTable *table);
int numberOfEmptyCells(HashTable *table);
void deleteTable(HashTable *table);
//void printLinesWithCollisions(HashTable *table, char fileName[]);
bool isInTable(HashTable *table, Line *line);

#endif // HASHTABLE_H
