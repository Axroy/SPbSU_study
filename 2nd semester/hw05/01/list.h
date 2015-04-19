#pragma once

#include <QString>
#include "list.h"

class List
{
public:
    List();
    ~List();
    void add(QString value);
    void remove(QString value);
    void print();
    bool isEmpty();
    bool hasValue(QString value);
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
