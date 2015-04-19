#include <QCoreApplication>
#include <iostream>
#include "hashTable.h"
#include "list.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    /*HashTable *table = new HashTable;
    delete table;*/

    List *list = new List;
    list->add("14251345");
    list->add("slghs");
    list->print();
    list->remove("14251345");
    std::cout << "\n";
    list->print();
    delete list;

    return a.exec();
}
