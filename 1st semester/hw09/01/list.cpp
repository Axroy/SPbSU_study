#include <stdio.h>
#include "list.h"
#include "line.h"


struct ListElement
{
    Line *line;
    ListElement *next;
};

struct List
{
    ListElement *head;
    int numberOfElements;
};


ListElement *createElement(ListElement *next)
{
    ListElement *node = new ListElement;
    node->next = next;

    return node;
}

ListElement *createElement(Line *line, ListElement *next)
{
    ListElement *node = new ListElement;
    Line *newLine = createLine(line);
    node->next = next;
    node->line = newLine;
    return node;
}

List *createList()
{
    List *list = new List;
    ListElement *node = createElement(nullptr);
    list->head = node;
    list->numberOfElements = 0;

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
            deleteLine(current->line);
            delete current;
            node = node->next;
        }
    }
    delete list->head;
    delete list;
}

void insertFirst(List *list, Line *line)
{
    ListElement *node = createElement(line, list->head->next);
    list->head->next = node;
    list->numberOfElements++;
}

void insertAfter(List *list, ListElement *element, Line *line)
{
    ListElement *node = createElement(line, element->next);
    element->next = node;
    list->numberOfElements++;
}

void insertSorted(List *list, Line *line)
{
    ListElement *current = list->head->next;
    if (isEmpty(list) || compareLines(current->line, line) == 1 || compareLines(current->line, line) == 0)
        insertFirst(list, line);
    else
    {
        while (!endOfList(current) && compareLines(current->next->line, line) == -1)
        {
            current = current->next;
        }
        insertAfter(list, current, line);
    }
}

void insertSortedSingle(List *list, Line *line)
{
    ListElement *current = list->head->next;
    if (!isEmpty(list) && compareLines(current->line, line) == 0)
        return;
    else if (isEmpty(list) || compareLines(current->line, line) == 1)
             insertFirst(list, line);
    else
    {
        while (!endOfList(current) && compareLines(current->next->line, line) == -1)
        {
            current = current->next;
        }
        if (!endOfList(current) && compareLines(current->next->line, line) == 0)
            return;
        insertAfter(list, current, line);
    }
}

void deleteFirst(List *list)
{
    if (!isEmpty(list))
    {
        ListElement *node = list->head->next;
        list->head->next = node->next;
        deleteLine(node->line);
        delete node;
    }
    list->numberOfElements--;
}

void deleteElement(List *list, Line *line)
{
    if (!isEmpty(list))
    {
        ListElement *node = list->head->next;
        if (areEqual(node->line, line))
            deleteFirst(list);
        else
        {
            while (!endOfList(node) && !areEqual(node->next->line, line))
                node = node->next;
            if (!endOfList(node))
            {
                ListElement *current = node;
                node = node->next;
                current->next = node->next;
                deleteLine(node->line);
                delete node;
            }
        }
    }
    list->numberOfElements--;
}

void printList(List *list)
{
        if (!isEmpty(list))
        {
            ListElement *node = list->head->next;
            while (!endOfList(node))
            {
                printLine(node->line);
                node = node->next;
            }
            printLine(node->line);
        }
}



int numberOfElements(List *list)
{
    return list->numberOfElements;
}


Line *differentElements(List *list)
{
    Line *line = createLine();

    if (isEmpty(list))
        return line;

    if (list->head->next->next == nullptr)
    {
        concat(list->head->next->line, line);
        return line;
    }

    ListElement *previous = list->head->next;
    ListElement *current = list->head->next->next;

    while (!endOfList(current))
    {
        if (!areEqual(current->line, previous->line))
        {
            if(!isEmpty(line))
                addSymbol(line, ' ');
            concat(previous->line, line);
        }
        current = current->next;
        previous = previous->next;
    }

    addSymbol(line, ' ');
    if (areEqual(previous->line, current->line))
        concat(previous->line, line);
    else
        concat(current->line, line);

    return line;
}


void printDifferentElementsWithNumbers(List *list)
{
    Line *line = createLine();

    if (isEmpty(list))
        return;

    if (list->head->next->next == nullptr)
    {
        printLine(list->head->next->line);
        printf("1\n");
        return;
    }

    ListElement *previous = list->head->next;
    ListElement *current = list->head->next->next;

    int counter = 0;
    while (!endOfList(current))
    {
        counter++;
        if (!areEqual(current->line, previous->line))
        {
            if(!isEmpty(line))
                addSymbol(line, ' ');
            concat(previous->line, line);
            printLine(line);
            printf("%d\n", counter);

            clearLine(line);
            counter = 0;
        }
        current = current->next;
        previous = previous->next;
    }

    if(!isEmpty(line))
        addSymbol(line, ' ');
    if (areEqual(previous->line, current->line))
    {
        concat(previous->line, line);
        printLine(line);
        printf("%d\n", counter + 1);
    }
    else
    {
        printLine(current->line);
        printf("1\n");
    }
}


char *firstElementSymbols(List *list)
{
    return getSymbols(list->head->next->line);
}


bool hasSuchElement(List *list, Line *line)
{
    if (isEmpty(list))
        return false;

    ListElement *current = list->head->next;
    while (!endOfList(current))
        if (areEqual(line, current->line))
            return true;

    if (areEqual(line, current->line))
        return true;

    return false;
}
