#include <stdio.h>
#include "circularList.h"

CircularListElement *createElement(int value, CircularListElement *next)
{
    CircularListElement *node = new CircularListElement;
    node->next = next;
    node->data = value;
    return node;
}

CircularList *createList()
{
    CircularList *list = new CircularList;
    CircularListElement *node = createElement(0, nullptr);
    list->head = node;
    return list;
}

bool isEmpty(CircularList *list)
{
    return list->head->next == nullptr;
}

bool hasOneElement(CircularList *list)
{
    return list->head->next->next == list->head->next;
}

bool endOfList(CircularList *list, CircularListElement *node)
{
    return node->next == list->head->next;
}

void deleteList(CircularList *list)
{
    if (!isEmpty(list))
    {
        CircularListElement *node = list->head->next;
        CircularListElement *current = node;
        while (!endOfList(list, node))
        {
            current = node;
            delete current;
            node = node->next;
        }
    }
    delete list->head;
    delete list;
}

void insertAfterFirst(CircularList *list, int value)
{
    if(isEmpty(list))
    {
        CircularListElement *node = createElement(value, nullptr);
        list->head->next = node;
        node->next = node;
    }
    else
    {
        CircularListElement *node = createElement(value, list->head->next->next);
        list->head->next->next = node;
    }
}

void insertAfterElement(CircularList *list, CircularListElement *element, int value)
{
    CircularListElement *node = createElement(value, element->next);
    element->next = node;
}

void deleteFirst(CircularList *list)
{
    if (!isEmpty(list))
    {
        CircularListElement *node = list->head->next;
        CircularListElement *current = list->head->next;
        while (!endOfList(list, current))
            current = current->next;
        current->next = list->head->next->next;
        list->head->next = node->next;
        delete node;
    }
}

void deleteElement(CircularList *list, int value)
{
    if (!isEmpty(list))
    {
        CircularListElement *node = list->head->next;
        if (node->data == value)
            deleteFirst(list);
        else
        {
            while (!endOfList(list, node) && node->next->data != value)
                node = node->next;
            if (!endOfList(list, node))
            {
                CircularListElement *current = node;
                node = node->next;
                current->next = node->next;
                delete node;
            }
        }
    }
}

void printList(CircularList *list)
{
        if (!isEmpty(list))
        {
            if(!hasOneElement(list))
            {
                CircularListElement *node = list->head->next->next;
                while (!endOfList(list, node))
                {
                    printf("%d ", node->data);
                    node = node->next;
                }
                printf("%d ", node->data);
                node = node->next;
                printf("%d ", node->data);
            }
            else
                printf("%d", list->head->next->data);
        }
}

int survivor(CircularList *list, int amount, int period)
{
    for (int i = amount; i > 0; i--)
        insertAfterFirst(list, i);
    CircularListElement *current = list->head->next->next;
    CircularListElement *nextAfterCurrent = current;
    while (!hasOneElement(list))
    {
        for (int i = 1; i < period; i++)
            current = current->next;
        nextAfterCurrent = current->next;
        deleteElement(list, current->data);
        current = nextAfterCurrent;
    }
    return list->head->next->data;
}
