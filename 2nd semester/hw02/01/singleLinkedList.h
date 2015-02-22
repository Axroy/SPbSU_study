#ifndef SINGLELINKEDLIST_H
#define SINGLELINKEDLIST_H

#include "list.h"

class SingleLinkedList : public List
{
public:
    SingleLinkedList();
    ~SingleLinkedList();
    void add(int value);
    void remove(int value);
    void print();
};

#endif // SINGLELINKEDLIST_H
