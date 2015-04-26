#include <iostream>
#include "linkedList.h"

LinkedList::LinkedList() : head(new ListElement(0, nullptr))
{}

LinkedList::~LinkedList()
{
    ListElement *current = head;
    ListElement *removedElement = head;

    while (current->next != nullptr)
    {
        current = current->next;
        delete removedElement;
        removedElement = current;
    }
    delete current;
}

void LinkedList::add(int value)
{
    ListElement *node = new ListElement(value, head->next);
    head->next = node;
    size++;
}

void LinkedList::remove(int value)
{
    if (head->next == nullptr)
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
    }
    size--;
}

void LinkedList::print()
{
    if (head->next == nullptr)
        return;

    ListElement *current = head->next;
    while (current->next != nullptr)
    {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << current->data;
}


LinkedList::ListElement::ListElement(int value, LinkedList::ListElement *nextElement)
{
    data = value;
    next = nextElement;
}
