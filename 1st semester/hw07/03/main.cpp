#include <stdio.h>
#include "hashTable.h"
#include "line.h"

bool isNotPartOfAWord(char symbol)
{
    return (int)symbol < 'A' || ((int)symbol > 'Z' && (int)symbol < 'a') || (int)symbol > 'z';
}

int main()
{
    printf("The program counts number of uses of each word in a file using hash-table.\n");
    const int size = 1000;

    char fileName[size] = "";
    printf("Enter name of a file: ");
    scanf("%s", &fileName);

    FILE *file = fopen(fileName, "r");
    if (file == nullptr)
    {
        printf("File not found!");
        return 0;
    }


    HashTable *table = createTable();
    Line *line = createLine();

    char symbol = 0;
    while (!feof(file))
    {
        symbol = fgetc(file);
        while(!isNotPartOfAWord(symbol)&& !feof(file))
        {
            addSymbol(line, symbol);
            symbol = fgetc(file);
        }
        addLine(table, line);
        clearLine(line);
    }

    fclose(file);

    printf("Number of uses of each word:\n");
    printNumberOfEachWord(table);

    printf("\n\n\n----------------------\n");
    printf("Hash-table parameters\n");
    printf("----------------------\n\n");

    printf("Load factor: %3.2f\n", loadFactor(table));
    printf("Average chain length: %3.2f\n", averageChainLength(table));
    printf("Maximal chain length: %d\n", maxChainLength(table));

    printf("And its elements:\n");
    line = maxChainLengthElements(table);
    printLine(line);
    deleteLine(line);

    printf("\nTotal number of elements: %d\n", totalNumberOfElements(table));
    printf("Total number of empty cells: %d\n", numberOfEmptyCells(table));

    deleteTable(table);

    return 0;
}

