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

