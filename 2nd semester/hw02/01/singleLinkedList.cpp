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
    ListElement *node = new ListElement(value, nullptr);
    head->next = node;
}

void SingleLinkedList::remove(int value)
{

}

void SingleLinkedList::print()
{

}

