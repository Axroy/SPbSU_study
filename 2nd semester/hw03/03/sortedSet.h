#pragma once

#include "linkedList.h"

class SortedSet
{
public:
    SortedSet();
    ~SortedSet();
    void add(LinkedList *newList);
    void remove(LinkedList *toRemove);
    bool isEmpty();

private:
    class SetElement
    {
    public:
        SetElement(LinkedList *newList, SetElement *nextElement);

        LinkedList *list;
        SetElement *next;
    };

    SetElement *head;

    void addFirst(LinkedList *newList);
};
