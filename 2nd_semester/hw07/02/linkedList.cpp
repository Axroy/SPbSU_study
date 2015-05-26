#include "linkedList.h"

LinkedList::LinkedList() : head(nullptr), size(0)
{
}

LinkedList::~LinkedList()
{
    ListElement *current = head;
    ListElement *toBeRemoved = head;

    while (current->next != nullptr)
    {
        current = current->next;
        delete toBeRemoved;
        toBeRemoved = current;
    }
    delete current->next;
}

void LinkedList::add(int value)
{
    ListElement *newElement = new ListElement(value, head);
    head = newElement;
    size++;
}

void LinkedList::remove(int value) throw (RemovalOfNonExisting)
{
    if (isEmpty())
        return;

    ListElement *current = head;

    if (current->value == value)
    {
        head = current->next;
        delete current;
        size--;
        return;
    }

    while (current->next != nullptr && current->next->value != value)
        current = current->next;
    if (current->next != nullptr)
    {
        ListElement *toBeRemoved = current->next;
        current->next = toBeRemoved->next;
        delete toBeRemoved;
        size--;
    }
    else
        throw RemovalOfNonExisting();
}

bool LinkedList::exists(int value)
{
    if (isEmpty())
        return false;

    ListElement *current = head;
    while (current->value != value && current->next != nullptr)
        current = current->next;
    return current->value == value;
}

bool LinkedList::isEmpty()
{
    return head == nullptr;
}

int LinkedList::getSize()
{
    return size;
}

LinkedList::ListElement::ListElement(int newValue, LinkedList::ListElement *newNext) : value(newValue), next(newNext)
{
}
