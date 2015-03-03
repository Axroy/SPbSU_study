#pragma once

#include "listsComparator.h"

class LinkedList : public ListsComparator
{
public:
    LinkedList();
    ~LinkedList();
    void add(int value);
    void remove(int value);
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
