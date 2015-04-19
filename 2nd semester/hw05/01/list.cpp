#include <iostream>
#include "list.h"

List::List()
{
    head = new ListElement(0, nullptr);
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
}

void List::remove(QString value)
{
    if (head->next == nullptr)
        return;

    ListElement *current = head->next;

    if (current->data == value)
    {
        head->next = current->next;
        delete current;
        return;
    }

    while (current->next != nullptr && current->next->data != value)
        current = current->next;

    if (current->next != nullptr)
    {
        ListElement *removedElement = current->next;
        current->next = removedElement->next;
        delete removedElement;
    }
}

void List::print()
{
    if (head->next == nullptr)
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
    return head->next == nullptr;
}



List::ListElement::ListElement(QString value, List::ListElement *nextElement)
{
    data = value;
    next = nextElement;
}
