#pragma once

#include <QString>
#include "list.h"

///Single linked list
class List
{
public:
    List();
    ~List();

    ///Adds value to head of the list.
    void add(QString value);\
    ///Removes a value from the list.
    void remove(QString value);
    ///Prints list to console.
    void print();
    ///Returns true if the list has no elements.
    bool isEmpty();
    ///Returns true if the list has certain value.
    bool hasValue(QString value);
    ///Returns number of elements in the list.
    int numberOfElements();

private:
    class ListElement
    {
    public:
        ListElement(QString value, ListElement *nextElement);

        QString data;
        ListElement *next;
    };

    ListElement *head;
    int size;
};
