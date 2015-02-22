#include <iostream>
#include "list.h"
#include "singleLinkedList.h"


int main()
{
    List *example = new SingleLinkedList;
    example->add(1);
    example->add(2);
    example->add(3);

    example->print();

    return 0;
}

