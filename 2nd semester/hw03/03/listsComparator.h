#pragma once
///Class used for comparing lists. Comparison is based on lists' length.
class ListsComparator
{
public:
    ///Default constructor
    ListsComparator();
    ///Compares current object with list: 1 - list > current, 0 - list = current, -1 - list < current.
    int compareTo(ListsComparator *list);

protected:
    int size;
};

