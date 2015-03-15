#pragma once

enum comparison
{
    equal,
    bigger,
    lesser
};

///Class used for comparing lists. Comparison is based on lists' length.
class ListsComparator
{
public:
    ///Default constructor
    ListsComparator();
    ///Compares current object with list: bigger - list > current, equal - list = current, lesser - list < current.
    comparison compareTo(ListsComparator *list);
    ///Returns size of current list
    int getSize();

protected:
    int size;
};

