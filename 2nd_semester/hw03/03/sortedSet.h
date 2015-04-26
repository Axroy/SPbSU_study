#pragma once

#include "linkedList.h"
///Represents a set of linked lists sorted by ascention of their sizes
class SortedSet
{
public:
    ///Constructor
    SortedSet();
    ///Destructor
    ~SortedSet();
    ///Adds a list to the set
    void add(LinkedList *newList);
    ///Removes certain list from the set
    void remove(LinkedList *toRemove);
    ///Prints sizes of elements in the set
    void print();

private:
    class SetElement
    {
    public:
        SetElement(LinkedList *newList, SetElement *nextElement);

        LinkedList *list;
        SetElement *next;
    };

    SetElement *head;

    bool isEmpty();
    void addFirst(LinkedList *newList);
};
