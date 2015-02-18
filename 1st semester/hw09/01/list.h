#ifndef LIST_H
#define LIST_H

#include "line.h"

struct ListElement;
struct List;

ListElement *createElement(ListElement *next);
ListElement *createElement(Line *line, ListElement *next);
List *createList();
void deleteList(List *list);
bool isEmpty(List *list);
bool endOfList(List *list);
void insertFirst(List *list, Line *line);
void insertAfter(List *list, ListElement *elem, Line *line);
void insertSorted(List *list, Line *line);
void insertSortedSingle(List *list, Line *line);
void deleteFirst(List *list);
void deleteElement(List *list, Line *line);
void printList(List *list);
int numberOfElements(List *list);
Line *differentElements(List *list);
void printDifferentElementsWithNumbers(List *list);
char *firstElementSymbols(List *list);
bool hasSuchElement(List *list, Line *line);

#endif // LIST_H
