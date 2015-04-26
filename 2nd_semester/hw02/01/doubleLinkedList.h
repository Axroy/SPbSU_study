#pragma once

#include "list.h"

class DoubleLinkedList : public List
{
public:
    DoubleLinkedList();
    ~DoubleLinkedList();
    void add(int value);
    void remove(int value);
    void print();

private:
    class ListElement
    {
    public:
        ListElement(int value, ListElement *nextElement, ListElement *previousElement);

        int data;
        ListElement *next;
        ListElement *previous;
    };
    ListElement *head;
    ListElement *tail;
};

