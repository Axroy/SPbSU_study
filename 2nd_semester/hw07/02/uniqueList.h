#pragma once

class UniqueList
{
public:
    UniqueList();
    ~UniqueList();
    void add(int value);
    void remove(int value);
    bool exists(int value);
    bool isEmpty();
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

class AdditionOfExisting{};
class RemovalOfNonExisting{};
