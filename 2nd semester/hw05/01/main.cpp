#include <QCoreApplication>
#include <iostream>
#include "hashTable.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    HashTable *table = new HashTable(5);
    table->addValue("1111");
    table->addValue("2222");
    table->printTable();
    std::cout << "\n";
    table->removeValue("2222");
    table->printTable();
    std::cout << "\n" << table->numberOfEmptyCells();
    std::cout << "\n\n";
    table->showStats();
    delete table;

    return a.exec();
}
