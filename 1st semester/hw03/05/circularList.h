#ifndef CIRCULARLIST_H_INCLUDED
#define CIRCULARLIST_H_INCLUDED

struct CircularListElement
{
    int data;
    CircularListElement *next;
};

struct CircularList
{
    CircularListElement *head;
};

CircularListElement *createElement(int value, CircularListElement *next);
CircularList *createList();
void deleteList(CircularList *list);
bool isEmpty(CircularList *list);
bool endOfList(CircularList *list, CircularListElement *node);
bool hasOneElement(CircularList *list);
void insertAfterFirst(CircularList *list, int value);
void insertAfterElement(CircularList *list, CircularListElement *elem, int value);
void deleteFirst(CircularList *list);
void deleteElement(CircularList *list, int value);
void printList(CircularList *list);
int survivor(CircularList *list, int amount, int period);

#endif // CIRCULARLIST_H_INCLUDED
