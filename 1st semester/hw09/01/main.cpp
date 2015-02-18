#include <stdio.h>
#include "hashTable.h"
#include "line.h"

int main()
{
    printf("The program writes to an output file strings that appear in both input files.\n");
    const int size = 1000;

    char fileName[size] = "";
    printf("Enter the name of the first input file: ");
    scanf("%s", &fileName);

    FILE *input = fopen(fileName, "r");
    if (input == nullptr)
    {
        printf("File not found!");
        return 0;
    }


    HashTable *table = createTable();
    Line *line = createLine();

    char symbol = 0;
    while (!feof(input))
    {
        symbol = fgetc(input);
        while(symbol != '\n' && !feof(input))
        {
            addSymbol(line, symbol);
            symbol = fgetc(input);
        }
        addLineSingle(table, line);
        clearLine(line);
    }

    fclose(input);


    printf("Enter the name of the second input file: ");
    scanf("%s", &fileName);

    input = fopen(fileName, "r");
    if (input == nullptr)
    {
        printf("File not found!");
        return 0;
    }

    printf("Enter the name of the output file: ");
    scanf("%s", &fileName);
    FILE *output = fopen(fileName, "w");

    symbol = 0;
    while (!feof(input))
    {
        symbol = fgetc(input);
        while(symbol != '\n' && !feof(input))
        {
            addSymbol(line, symbol);
            symbol = fgetc(input);
        }
        if (isInTable(table, line))
            fprintf(output, "%s\n", getSymbols(line));
        clearLine(line);
    }

    deleteLine(line);
    fclose(input);
    fclose(output);

    deleteTable(table);

    return 0;
}

