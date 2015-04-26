#pragma once

#include "list.h"

class SingleLinkedList : public List
{
public:
    SingleLinkedList();
    ~SingleLinkedList();
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


