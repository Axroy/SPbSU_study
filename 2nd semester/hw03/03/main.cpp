#include <iostream>
#include "linkedList.h"

int main()
{
    LinkedList *list1 = new LinkedList;
    LinkedList *list2 = new LinkedList;
    list2->add(1);
    list2->add(2);
    list2->add(3);
    list1->add(10);

    list2->remove(3);
    list2->remove(2);
    list2->remove(1);

    std::cout << list1->compareTo(list2);

    return 0;
}

