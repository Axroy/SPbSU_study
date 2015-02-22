#include "doubleLinkedList.h"

DoubleLinkedList::DoubleLinkedList()
{
    head = new ListElement(0, nullptr, nullptr);
    tail = head;
}

DoubleLinkedList::~DoubleLinkedList()
{

}

void DoubleLinkedList::add(int value)
{
    tail->next = new ListElement(value, nullptr, tail);
    tail = tail->next;
}

void DoubleLinkedList::remove(int value)
{

}

void DoubleLinkedList::print()
{

}


DoubleLinkedList::ListElement::ListElement(int value, DoubleLinkedList::ListElement *nextElement, DoubleLinkedList::ListElement *previousElement)
{
    data = value;
    next = nextElement;
    previous = previousElement;
}
