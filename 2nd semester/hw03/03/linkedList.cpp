#include "linkedList.h"

LinkedList::LinkedList()
{
    head = new ListElement(0, nullptr);
}

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
    delete current->next;
}


LinkedList::ListElement::ListElement(int value, LinkedList::ListElement *nextElement)
{
    data = value;
    next = nextElement;
}
