#include <stdio.h>
#include "line.h"


struct Line
{
    int length;
    char *symbols;
};


Line *createLine()
{
    Line *newLine = new Line;
    char *newSymbols = new char[1];
    newSymbols = {'\0'};
    newLine->symbols = newSymbols;
    newLine->length = 0;


    return newLine;
}

Line *createLine(int length)
{
    Line *newLine = new Line;
    char *newSymbols = new char[length];

    for (int i = 0; i < length; i++)
        newSymbols[i] = ' ';
    newSymbols[length] = '\0';

    newLine->symbols = newSymbols;
    newLine->length = length;


    return newLine;
}

Line *createLine(int length, char symbols[])
{
    Line *newLine = new Line;
    char *newSymbols = new char[length + 1];

    for (int i = 0; i < length; i++)
        newSymbols[i] = symbols[i];
    newSymbols[length] = '\0';

    newLine->symbols = newSymbols;
    newLine->length = length;


    return newLine;
}

void deleteLine(Line *line)
{
    delete[] line->symbols;
    delete line;

    return;
}


Line *clone(Line *line)
{
    Line *newLine = createLine(line->length, line->symbols);
    return newLine;
}


void concat(Line *argumentLine, Line *currentLine)
{
    int resultingLength = currentLine->length + argumentLine->length;
    char *newSymbols = new char[resultingLength];
    int currentLinePos = 0;

    for (currentLinePos = 0; currentLinePos < currentLine->length; currentLinePos++)
        newSymbols[currentLinePos] = currentLine->symbols[currentLinePos];

    int argLinePos = 0;
    while (currentLinePos < resultingLength)
    {
        newSymbols[currentLinePos] = argumentLine->symbols[argLinePos];
        argLinePos++;
        currentLinePos++;
    }

    delete[] currentLine->symbols;

    currentLine->symbols = newSymbols;
    currentLine->length = resultingLength;

}


int lineLength(Line *line)
{
    return line->length;
}


void printLine(Line *line)
{
    for (int i = 0; i < line->length; i++)
        printf("%c", line->symbols[i]);
    printf("|endl\n");
}


bool areEqual(Line *line1, Line *line2)
{
    int i = 0;
    while (i < line1->length && i < line2->length)
    {
        if (line1->symbols[i] != line2->symbols[i])
            return false;
        i++;
    }
    return true;
}


bool isEmpty(Line *line)
{
    return line->length == 0;
}


Line *copy(Line *line, int startingPos, int length)
{
    Line *newLine = new Line;

    char *newSymbols = new char[length + 1];
    int linePos = startingPos;
    for (int i = 0; i < length; i++)
    {
        newSymbols[i] = line->symbols[linePos];
        linePos++;
    }
    newSymbols[length] = '\0';

    newLine->length = length;
    newLine->symbols = newSymbols;

    return newLine;
}


char *getSymbols(Line *line)
{
    char *symbols = new char[line->length];
    for (int i = 0; i < line->length; i++)
        symbols[i] = line->symbols[i];

    return symbols;
}


void addLength(Line *line, int length)
{
    int resultingLength = line->length + length;
    char *newSymbols = new char[resultingLength + 1];

    for (int i = 0; i < line->length; i++)
        newSymbols[i] = line->symbols[i];
    for (int i = line->length; i < resultingLength; i++)
        newSymbols[i] = ' ';
    newSymbols[resultingLength] = '\0';

    delete[] line->symbols;
    line->symbols = newSymbols;
    line->length = resultingLength;
}
