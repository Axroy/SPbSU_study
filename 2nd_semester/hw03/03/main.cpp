#include <iostream>
#include "linkedList.h"
#include "sortedSet.h"
#include "sortedSetTests.h"

int main()
{
    SortedSetTests test;
    QTest::qExec(&test);

    /*LinkedList *list1 = new LinkedList;
    LinkedList *list2 = new LinkedList;
    LinkedList *list3 = new LinkedList;
    LinkedList *list4 = new LinkedList;
    list1->add(10);

    list2->add(1);
    list2->add(2);
    list2->add(3);

    list3->add(1);
    list3->add(1);
    list3->add(1);
    list3->add(1);

    list4->add(1);
    list4->add(1);

    SortedSet *set = new SortedSet;
    set->add(list1);
    set->add(list2);
    set->add(list3);
    set->add(list4);

    set->print();

    set->remove(list1);

    std::cout << "\n";
    set->print();

    delete set;

    delete list1;
    delete list2;
    delete list3;
    delete list4;*/

    return 0;
}

