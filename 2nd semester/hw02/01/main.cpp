#include <iostream>
#include "list.h"
#include "singleLinkedList.h"


int main()
{
    List *example = new SingleLinkedList;
    example->add(5);
    example->add(4);
    example->add(3);
    example->add(2);
    example->add(1);

    example->print();

    example->remove(5);
    example->print();

    return 0;
}

