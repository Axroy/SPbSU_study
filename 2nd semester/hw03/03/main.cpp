#include <iostream>
#include "linkedList.h"

int main()
{
    LinkedList *list1 = new LinkedList;
    LinkedList *list2 = new LinkedList;

    std::cout << list1->compareTo(list2);

    return 0;
}

