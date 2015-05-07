#include <QCoreApplication>
#include <iostream>
#include <string>

#include "hashTable.h"
#include "hashTableTests.h"
#include "listTests.h"
#include "hashFunctionsTests.h"

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

int main()
{
    HashTableTests tableTests;
    QTest::qExec(&tableTests);

    std::cout << "\n";
    ListTests listTests;
    QTest::qExec(&listTests);

    std::cout << "\n";
    hashFunctionsTests hashTests;
    QTest::qExec(&hashTests);

    std::cout << "\n\nHash table for strings\n";

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
                std::cout << "\nEnter value to be added: ";
                std::cin >> input;
                table->addValue(QString::fromStdString(input));
                break;

            case removeValue:
                std::cout << "\nEnter value to be removed: ";
                std::cin >> input;
                table->removeValue(QString::fromStdString(input));
                break;

            case findValue:
                std::cout << "\nEnter value to be found: ";
                std::cin >> input;
                std::cout << "Position in the table: " << table->findValue(QString::fromStdString(input));
                break;

            case stats:
                std::cout << "\n";
                table->showStats();
                break;

            case hash:
            {
                int hashFunctionType = 0;
                std::cout << "\nAvailable hash functions:\n";
                std::cout << "0 - polynomial\n";
                std::cout << "1 - sum of symbols\n";
                std::cout << "Which do you want?:";
                std::cin >> hashFunctionType;
                HashFunctions *hashFunction = nullptr;
                switch (hashFunctionType)
                    {
                        case polynomial:
                            hashFunction = new PolynomialHash(size);
                            break;

                        case symbolsSum:
                            hashFunction = new SymbolsSumHash(size);
                            break;
                    }
                table->changeHashFunction(hashFunction);
                break;
            }

            case print:
                std::cout << "\n";
                table->printTable();
                break;

            default:
                break;
        }
    }

    return 0;
}
