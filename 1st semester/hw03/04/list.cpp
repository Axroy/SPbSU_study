#include <stdio.h>
#include "list.h"

ListElement *createElement(int value, ListElement *next)
{
    ListElement *node = new ListElement;
    node->next = next;
    node->data = value;
    return node;
}

List *createList()
{
    List *list = new List;
    ListElement *node = createElement(0, nullptr);
    list->head = node;

    return list;
}

bool isEmpty(List *list)
{
    return list->head->next == nullptr;
}

bool endOfList(ListElement *node)
{
    return node->next == nullptr;
}

void deleteList(List *list)
{
    if (!isEmpty(list))
    {
        ListElement *node = list->head->next;
        ListElement *current = node;
        while (!endOfList(node))
        {
            current = node;
            delete current;
            node = node->next;
        }
    }
    delete list->head;
    delete list;
}

void insertFirst(List *list, int value)
{
    ListElement *node = createElement(value, list->head->next);
    list->head->next = node;
}

void insertAfter(List *list, ListElement *element, int value)
{
    ListElement *node = createElement(value, element->next);
    element->next = node;
}

void insertSorted(List *list, int value)
{
    ListElement *current = list->head->next;
    if (isEmpty(list) || current->data >= value)
        insertFirst(list, value);
    else
    {
        while (!endOfList(current) && current->next->data < value)
        {
            current = current->next;
        }
        insertAfter(list, current, value);
    }
}

void deleteFirst(List *list)
{
    if (!isEmpty(list))
    {
        ListElement *node = list->head->next;
        list->head->next = node->next;
        delete node;
    }
}

void deleteElement(List *list, int value)
{
    if (!isEmpty(list))
    {
        ListElement *node = list->head->next;
        if (node->data == value)
            deleteFirst(list);
        else
        {
            while (!endOfList(node) && node->next->data != value)
                node = node->next;
            if (!endOfList(node))
            {
                ListElement *current = node;
                node = node->next;
                current->next = node->next;
                delete node;
            }
        }
    }
}

void printList(List *list)
{
        if (!isEmpty(list))
        {
            ListElement *node = list->head->next;
            while (!endOfList(node))
            {
                printf("%d ", node->data);
                node = node->next;
            }
            printf("%d ", node->data);
        }
}
