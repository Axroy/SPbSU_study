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

Line *createLine(char symbols[])
{
    Line *newLine = new Line;

    int i = 0;
    while (symbols[i] != '\0')
        i++;

    newLine->length = i;

    char *newSymbols = new char[newLine->length + 1];
    for (int i = 0; i < newLine->length; i++)
        newSymbols[i] = symbols[i];
    newSymbols[newLine->length] = '\0';

    newLine->symbols = newSymbols;


    return newLine;
}

Line *createLine(Line *line)
{
    Line *newLine = new Line;

    char *newSymbols = new char[line->length + 1];

    for (int i = 0; i < line->length; i++)
        newSymbols[i] = line->symbols[i];
    newSymbols[line->length] = '\0';

    newLine->symbols = newSymbols;
    newLine->length = line->length;

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
    char *newSymbols = new char[resultingLength + 1];
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
    newSymbols[resultingLength] = '\0';

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
    if (line->length == 0)
    {
        printf("|EMPTY LINE|\n");
        return;
    }
    for (int i = 0; i <= line->length; i++)
        printf("%c", line->symbols[i]);
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


/*char *getSymbols(Line *line)
{
    char *symbols = new char[line->length];
    for (int i = 0; i < line->length; i++)
        symbols[i] = line->symbols[i];

    return symbols;
}*/

char *getSymbols(Line *line)
{
    return line->symbols;
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

char getSymbol(Line *line, int position)
{
    if (isEmpty(line))
        return '\0';

    return line->symbols[position];
}


void addSymbol(Line *line, char symbol)
{
    line->length++;

    char *newSymbols = new char[line->length + 1];
    for (int i = 0; i < line->length - 1; i++)
        newSymbols[i] = line->symbols[i];

    newSymbols[line->length - 1] = symbol;
    newSymbols[line->length] = '\0';

    delete[] line->symbols;
    line->symbols = newSymbols;
}


void clearLine(Line *line)
{
    char *newSymbols = new char[1];
    newSymbols = {'\0'};
    delete[] line->symbols;
    line->symbols = newSymbols;
    line->length = 0;
}


int compareLines(Line *line1, Line *line2)
{
    if (line1->length > line2->length)
        return 1;
    if (line1->length < line2->length)
        return -1;
    if (isEmpty(line1) && isEmpty(line2))
        return 0;

    int result = 0;
    for (int i = 0; i <= line1->length; i++)
    {
        if (line1->symbols[i] > line2->symbols[i])
            return 1;
        if (line1->symbols[i] < line2->symbols[i])
            return -1;
    }

    return result;
}
