#include "uniqueList.h"

void UniqueList::add(int value) throw (AdditionOfExisting)
{
    if (exists(value))
        throw AdditionOfExisting();

    /*ListElement *newElement = new ListElement(value, head);
    head = newElement;
    size++;*/
    LinkedList::add(value);
}
