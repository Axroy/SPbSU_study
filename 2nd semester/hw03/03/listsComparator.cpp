#include "listsComparator.h"


ListsComparator::ListsComparator() : size(0)
{

}

int ListsComparator::compareTo(ListsComparator *list)
{
    if (list->size > size)
        return 1;
    if (list->size < size)
        return -1;
    return 0;
}
