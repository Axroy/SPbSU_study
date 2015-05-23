#pragma once
#include "linkedList.h"

///Exception.
class AdditionOfExisting{};

///List with unique (all different) values.
class UniqueList : public LinkedList
{
public:
    ///Adds value to head of the list. Throws exception if the value exists.
    void add(int value) throw (AdditionOfExisting);
};
