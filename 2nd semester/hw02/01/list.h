#ifndef LIST_H
#define LIST_H

class List
{
public:
    List();
    virtual void add(int value) = 0;
    virtual void remove(int value) = 0;
    virtual void print() = 0;
};

#endif // LIST_H
