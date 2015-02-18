#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

struct ListElement
{
    int data;
    ListElement *next;
};

struct List
{
    ListElement *head;
};

ListElement *createElement(int value, ListElement *next);
List *createList();
void deleteList(List *list);
bool isEmpty(List *list);
bool endOfList(List *list);
void insertFirst(List *list, int value);
void insertAfter(List *list, ListElement *elem, int value);
void insertSorted(List *list, int value);
void deleteFirst(List *list);
void deleteElement(List *list, int value);
void printList(List *list);

#endif // LIST_H_INCLUDED
