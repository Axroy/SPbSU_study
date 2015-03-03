#pragma once

class ListsComparator
{
public:
    ListsComparator();
    int compareTo(ListsComparator *list);

protected:
    int size;
};

