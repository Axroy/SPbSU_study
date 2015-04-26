#include <iostream>
#include "doubleLinkedList.h"

DoubleLinkedList::DoubleLinkedList()
{
    head = new ListElement(0, nullptr, nullptr);
    tail = head;
}

DoubleLinkedList::~DoubleLinkedList()
{
    ListElement *current = head;
    ListElement *toRemove = head;

    while (current->next != nullptr)
    {
        current = current->next;
        delete toRemove;
        toRemove = current;
    }
    delete current->next;
}

void DoubleLinkedList::add(int value)
{
    tail->next = new ListElement(value, nullptr, tail);
    tail = tail->next;
}

void DoubleLinkedList::remove(int value)
{
    if (head->next == nullptr)
        return;

    ListElement *current = head->next;

    if (current->data == value)
    {
        head->next = current->next;
        current->next->previous = head;
        delete current;
        return;
    }

    while (current->next != nullptr && current->next->data != value)
        current = current->next;

    if (current->next != nullptr)
    {
        ListElement *toRemove = current->next;
        if (toRemove->next != nullptr)
            toRemove->next->previous = current;
        current->next = toRemove->next;
        delete toRemove;
    }
}

void DoubleLinkedList::print()
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

int DoubleLinkedList::elementsNumber()
{
    if (head->next == nullptr)
        return 0;

    int result = 0;
    ListElement *current = head->next;
    while (current->next != nullptr)
    {
        result++;
        current = current->next;
    }
    result++;
    return result;
}


DoubleLinkedList::ListElement::ListElement(int value, DoubleLinkedList::ListElement *nextElement, DoubleLinkedList::ListElement *previousElement)
{
    data = value;
    next = nextElement;
    previous = previousElement;
}
