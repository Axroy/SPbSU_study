#include <iostream>
#include "list.h"

List::List() : head(new ListElement(0, nullptr)), size(0)
{
}

List::~List()
{
    ListElement *current = head;
    ListElement *removedElement = head;

    while (current->next != nullptr)
    {
        current = current->next;
        delete removedElement;
        removedElement = current;
    }
    delete current->next;
}

void List::add(QString value)
{
    ListElement *node = new ListElement(value, head->next);
    head->next = node;
    size++;
}

void List::remove(QString value)
{
    if (isEmpty())
        return;

    ListElement *current = head->next;

    if (current->data == value)
    {
        head->next = current->next;
        delete current;
        size--;
        return;
    }

    while (current->next != nullptr && current->next->data != value)
        current = current->next;

    if (current->next != nullptr)
    {
        ListElement *removedElement = current->next;
        current->next = removedElement->next;
        delete removedElement;
        size--;
    }
}

void List::print()
{
    if (isEmpty())
        return;

    ListElement *current = head->next;
    while (current->next != nullptr)
    {
        std::cout << current->data.toStdString() << " ";
        current = current->next;
    }
    std::cout << current->data.toStdString() << " ";
}

bool List::isEmpty()
{
    return size == 0;
}

bool List::hasValue(QString value)
{
    if (isEmpty())
        return 0;

    ListElement *current = head->next;
    while (current->next != nullptr)
    {
        if (current->data == value)
            return 1;
        current = current->next;
    }

    if (current->data == value)
        return 1;
    return 0;
}

int List::numberOfElements()
{
    return size;
}



List::ListElement::ListElement(QString value, List::ListElement *nextElement)
{
    data = value;
    next = nextElement;
}
