#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

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
};

#endif // DOUBLELINKEDLIST_H
