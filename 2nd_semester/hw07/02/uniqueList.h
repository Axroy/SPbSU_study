#pragma once

///List with unique (all different) values.
class UniqueList
{
public:
    UniqueList();
    ~UniqueList();
    ///Adds value to head of the list. Throws exception if the value exists.
    void add(int value);
    ///Removes value from the list. Throws exception if the value does not exist.
    void remove(int value);
    ///Returns true if value exists in the list.
    bool exists(int value);
    ///Returns true if the list contains nothing.
    bool isEmpty();
    ///Returns number of elements in the list.
    int getSize();

private:
    class ListElement
    {
    public:
        ListElement(int newValue, ListElement *newNext);

        int value;
        ListElement *next;
    };

    ListElement *head;
    int size;
};

///Exceptions
class AdditionOfExisting{};
class RemovalOfNonExisting{};
