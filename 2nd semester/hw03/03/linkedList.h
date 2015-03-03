#pragma once

#include "listsComparator.h"

class LinkedList : public ListsComparator
{
public:
    LinkedList();
    ~LinkedList();

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
