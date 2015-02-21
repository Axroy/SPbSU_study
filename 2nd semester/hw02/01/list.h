#ifndef LIST_H
#define LIST_H

class List
{
public:
    List();
    ~List();
    virtual void add(int value) = 0;
    virtual void remove(int value) = 0;
    virtual void print() = 0;

protected:
    class ListElement
    {
    public:
        ListElement(int value, ListElement *next);

        int data;
        ListElement *next;
    };

    ListElement *head;
};

#endif // LIST_H
