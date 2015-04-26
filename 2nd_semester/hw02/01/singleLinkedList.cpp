#include <iostream>
#include "singleLinkedList.h"

SingleLinkedList::SingleLinkedList() : head(new ListElement(0, nullptr))
{
}

SingleLinkedList::~SingleLinkedList()
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

void SingleLinkedList::add(int value)
{
    ListElement *node = new ListElement(value, head->next);
    head->next = node;
    size++;
}

void SingleLinkedList::remove(int value)
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
        size--;
    }
}

void SingleLinkedList::print()
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

int SingleLinkedList::getSize()
{
    return size;
}

SingleLinkedList::ListElement::ListElement(int value, SingleLinkedList::ListElement *nextElement)
{
    data = value;
    next = nextElement;
}
