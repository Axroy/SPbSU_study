#include "listsComparator.h"


ListsComparator::ListsComparator() : size(0)
{}

comparison ListsComparator::compareTo(ListsComparator *list)
{
    if (list->size > size)
        return bigger;
    if (list->size < size)
        return lesser;
    return equal;
}

int ListsComparator::getSize()
{
    return size;
}
