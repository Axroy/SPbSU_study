#include <iostream>
#include "sortedSet.h"

SortedSet::SortedSet() : head(nullptr)
{}

SortedSet::~SortedSet()
{
    if (isEmpty())
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
    if (isEmpty() || current->list->compareTo(newList) == lesser || current->list->compareTo(newList) == equal)
        addFirst(newList);
    else
    {
        while (current->next != nullptr && current->next->list->compareTo(newList) == bigger)
            current = current->next;

        SetElement *node = new SetElement(newList, current->next);
        current->next = node;
    }
}

void SortedSet::remove(LinkedList *toRemove)
{
    if (isEmpty())
        return;

    SetElement *current = head;

    if (current->list->compareTo(toRemove) == equal)
    {
        head = current->next;
        delete current;
        return;
    }

    while (current->next != nullptr && current->next->list->compareTo(toRemove) != equal)
        current = current->next;

    if (current->next != nullptr)
    {
        SetElement *removedElement = current->next;
        current->next = removedElement->next;
        delete removedElement;
    }
}

void SortedSet::print()
{
    if (isEmpty())
        return;
    SetElement *current = head;
    while (current->next != nullptr)
    {
        std::cout << current->list->getSize() << " ";
        current = current->next;
    }
    std::cout << current->list->getSize();
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
