#include "doubleLinkedList.h"

DoubleLinkedList::DoubleLinkedList()
{
    head = new ListElement(0, nullptr, nullptr);
}

DoubleLinkedList::~DoubleLinkedList()
{

}

void DoubleLinkedList::add(int value)
{

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
