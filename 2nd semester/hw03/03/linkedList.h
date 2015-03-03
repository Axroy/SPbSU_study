#pragma once

#include "listsComparator.h"
///Single linked list
class LinkedList : public ListsComparator
{
public:
    ///Constructor
    LinkedList();
    ///Destructor
    ~LinkedList();
    ///Adds value to head of the list
    void add(int value);
    ///Removes a value from the list
    void remove(int value);
    ///Prints list to a console
    void print();

private:
    class ListElement
    {
    public:
        ListElement(int value, ListElement *nextElement);

        int data;
        ListElement *next;
    };

    ListElement *head;
};
