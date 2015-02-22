#include <iostream>
#include "list.h"
#include "singleLinkedList.h"
#include "doubleLinkedList.h"


int main()
{
    List *example = new SingleLinkedList;
    example->add(5);
    example->add(4);
    example->add(3);
    example->add(2);
    example->add(1);

    example->print();

    example->remove(4);

    std::cout << "\n";
    example->print();

    delete example;


    List *doubleListExample = new DoubleLinkedList;
    doubleListExample->add(4);
    doubleListExample->add(5);

    return 0;
}

