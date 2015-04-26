#include <iostream>
#include "singleLinkedList.h"

SingleLinkedList::SingleLinkedList()
{
    //SingleLinkedList *list = new SingleLinkedList;
    head = new ListElement(0, nullptr);
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

int SingleLinkedList::elementsNumber()
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


SingleLinkedList::ListElement::ListElement(int value, SingleLinkedList::ListElement *nextElement)
{
    data = value;
    next = nextElement;
}
