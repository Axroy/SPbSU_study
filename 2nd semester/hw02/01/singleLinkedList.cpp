#include <iostream>
#include "singleLinkedList.h"

SingleLinkedList::SingleLinkedList()
{
    //SingleLinkedList *list = new SingleLinkedList;
    head = new ListElement(0, nullptr);
}

void SingleLinkedList::add(int value)
{
    //std::cout << "worked";
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
    ListElement *&current = head->next;
    while (current != nullptr)
    {
        std::cout << current->data << " ";
        current = current->next;
    }
}

