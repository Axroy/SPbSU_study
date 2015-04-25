#include <QCoreApplication>
#include <iostream>
#include <string>
#include "hashTable.h"
#include "hashTableTests.h"

enum Command
{
    quit,
    add,
    removeValue,
    findValue,
    stats,
    hash,
    print,
};

void printInfo()
{
    std::cout << "\n\n";
    std::cout << "Accepted commands:\n";
    std::cout << "0 - quit\n";
    std::cout << "1 - add value to hash table\n";
    std::cout << "2 - remove value from hash table\n";
    std::cout << "3 - find value in hash table\n";
    std::cout << "4 - show statistics\n";
    std::cout << "5 - change hash function\n";
    std::cout << "6 - print table\n";
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    HashTableTests test;
    QTest::qExec(&test);

    std::cout << "Hash table for strings\n";

    std::cout << "Enter size for the table: ";
    int size = 0;
    std::cin >> size;
    HashTable *table = new HashTable(size);

    int cmd = -1;
    std::string input = "";

    while (cmd != quit)
    {
        printInfo();
        std::cout << "Enter command: ";
        std::cin >> cmd;

        switch (cmd)
        {
            case add:
                std::cout << "Enter value to be added: ";
                std::cin >> input;
                table->addValue(QString::fromStdString(input));
                break;

            case removeValue:
                std::cout << "Enter value to be removed: ";
                std::cin >> input;
                table->removeValue(QString::fromStdString(input));
                break;

            case findValue:
                std::cout << "Enter value to be found: ";
                std::cin >> input;
                std::cout << "Position in the table: " << table->findValue(QString::fromStdString(input));
                break;

            case stats:
                table->showStats();
                break;

            case hash:
            {
                int hashFunction = 0;
                std::cout << "Available hash functions:\n";
                std::cout << "0 - polynomial\n";
                std::cout << "1 - sum of symbols\n";
                std::cout << "Which do you want?:";
                std::cin >> hashFunction;
                table->changeHashFunction((Functions)hashFunction);
                break;
            }

            case print:
                table->printTable();
                break;

            default:
                break;
        }
    }


    return 0;
}
