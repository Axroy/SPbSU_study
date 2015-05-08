#include "uniqueList.h"

UniqueList::UniqueList() : head(nullptr), size(0)
{
}

UniqueList::~UniqueList()
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

void UniqueList::add(int value)
{
    if (exists(value))
        throw AdditionOfExisting();

    ListElement *newElement = new ListElement(value, head);
    head = newElement;
    size++;
}

void UniqueList::remove(int value)
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

bool UniqueList::exists(int value)
{
    if (isEmpty())
        return false;

    ListElement *current = head;
    while (current->value != value && current->next != nullptr)
        current = current->next;
    return current->value == value;
}

bool UniqueList::isEmpty()
{
    return head == nullptr;
}

int UniqueList::getSize()
{
    return size;
}



UniqueList::ListElement::ListElement(int newValue, UniqueList::ListElement *newNext) : value(newValue), next(newNext)
{
}
