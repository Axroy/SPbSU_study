#pragma once

///Exception.
class RemovalOfNonExisting{};

///Usual linked list.
class LinkedList
{
public:
    LinkedList();
    ~LinkedList();
    ///Adds value to head of the list.
    void add(int value);
    ///Removes value from the list. Throws exception if the value does not exist.
    void remove(int value) throw (RemovalOfNonExisting);
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
