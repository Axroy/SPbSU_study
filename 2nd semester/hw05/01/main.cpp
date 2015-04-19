#include <QCoreApplication>
#include <iostream>
#include "hashTable.h"
#include "HashTableTests.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    HashTableTests test;
    QTest::qExec(&test);

    /*HashTable *table = new HashTable();
    table->addValue("1111");
    table->addValue("2222");
    table->printTable();
    std::cout << "\n";
    table->removeValue("2222");
    table->printTable();
    delete table;*/

    return a.exec();
}
