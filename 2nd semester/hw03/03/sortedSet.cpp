#include "sortedSet.h"

SortedSet::SortedSet()
{
    head = nullptr;
}

SortedSet::~SortedSet()
{
    if (this->isEmpty())
        return;

    SetElement *current = head;
    SetElement *toRemove = head;

    while (current->next != nullptr)
    {
        current = current->next;
        delete toRemove;
        toRemove = current;
    }
    delete current;
}

void SortedSet::add(LinkedList *newList)
{
    SetElement *current = head;
    if (this->isEmpty() || current->list->compareTo(newList) == -1 || current->list->compareTo(newList) == 0)
        this->addFirst(newList);
    else
    {
        while (current->next != nullptr && current->next->list->compareTo(newList) == 1)
            current = current->next;

        SetElement *node = new SetElement(newList, current->next);
        current->next = node;
    }
}

void SortedSet::remove(LinkedList *toRemove)
{
    if (this->isEmpty())
        return;

    SetElement *current = head;

    if (current->list->compareTo(toRemove) == 0)
    {
        head = current->next;
        delete current;
        return;
    }

    while (current->next != nullptr && current->next->list->compareTo(toRemove) != 0)
        current = current->next;

    if (current->next != nullptr)
    {
        SetElement *removedElement = current->next;
        current->next = removedElement->next;
        delete removedElement;
    }
}

bool SortedSet::isEmpty()
{
    return head == nullptr;
}

void SortedSet::addFirst(LinkedList *newList)
{
    SetElement *node = new SetElement(newList, head);
    head = node;
}


SortedSet::SetElement::SetElement(LinkedList *newList, SortedSet::SetElement *nextElement)
{
    list = newList;
    next = nextElement;
}
