#pragma once

class List
{
public:
    List();
    virtual ~List(){}
    virtual void add(int value) = 0;
    virtual void remove(int value) = 0;
    virtual void print() = 0;
    virtual int getSize() = 0;

protected:
    int size;
};


