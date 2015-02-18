#include <stdio.h>
#include "line.h"

enum floatNumberState
{
    start,
    sign,
    integerPart,
    dot,
    fracPart,
    eSymbol,
    ePartSign,
    ePartDigits
};

bool isOperator(char symbol)
{
    return symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/';
}

bool isDigit(char symbol)
{
    return symbol >= '0' && symbol <= '9';
}

bool isFloatNumber(Line *line, int startingPos, int endingPos)
{
    floatNumberState state = start;
    int i = startingPos;
    bool error = false;
    char symbol = 0;

    while (i < endingPos && !error)
    {
        symbol = getSymbol(line, i);
        switch (state)
        {
            case start:
                if (symbol == '+' || symbol == '-')
                    state = sign;
                else if (isDigit(symbol))
                    state = integerPart;
                else
                    error = true;
                i++;
                break;

            case sign:
                if (isDigit(symbol))
                    state = integerPart;
                else
                    error = true;
                i++;
                break;

            case integerPart:
                if (!isDigit(symbol))
                {
                    if (symbol == 'E')
                        state = eSymbol;
                    else if (symbol == '.')
                        state = dot;
                    else
                        error = true;
                }
                i++;
                break;

            case dot:
                if (isDigit(symbol))
                    state = fracPart;
                else
                    error = true;
                i++;
                break;

            case fracPart:
                if (!isDigit(symbol))
                {
                    if (symbol == 'E')
                        state = eSymbol;
                    else
                        error = true;
                }
                i++;
                break;

            case eSymbol:
                if (symbol == '+' || symbol == '-')
                    state = ePartSign;
                else if (isDigit(symbol))
                    state = ePartDigits;
                else
                    error = true;
                i++;
                break;

            case ePartSign:
                if (isDigit(symbol))
                    state = ePartDigits;
                else
                    error = true;
                i++;
                break;

            case ePartDigits:
                if (!isDigit(symbol))
                    error = true;
                i++;
                break;
        }
    }

    if(state != integerPart && state != fracPart && state != ePartDigits)
        error = true;

    return !error;
}

void updateTree(Line *tree, char symbol1, int position)
{
    deleteSymbol(tree, position);
    addSymbol(tree, symbol1, position);
}

void updateTree(Line *tree, char symbol1, char symbol2, int position)
{
    deleteSymbol(tree, position);
    addSymbol(tree, symbol1, position);
    addSymbol(tree, symbol2, position + 1);
}

void updateTree(Line *tree, char symbol1, char symbol2, char symbol3, int position)
{
    deleteSymbol(tree, position);
    addSymbol(tree, symbol1, position);
    addSymbol(tree, symbol2, position + 1);
    addSymbol(tree, symbol3, position + 2);
}



int recursiveDescentParse(Line *tokens, Line *tree, int position)
{
    int errorPosition = -1;
    char tokensSymbol = getSymbol(tokens, position);
    char treeSymbol = getSymbol(tree, position);


    if (tokensSymbol != '\0' || treeSymbol != '\0')
    {
        switch (treeSymbol)
        {
            case 'E':
                updateTree(tree, 'T', 'e', position);
                errorPosition = recursiveDescentParse(tokens, tree, position);
                break;

            case 'e':
                updateTree(tree, '+', 'T', 'e', position);
                if (recursiveDescentParse(tokens, tree, position) != -1)
                {
                    updateTree(tree, '-', position);
                    if (recursiveDescentParse(tokens, tree, position) != -1)
                    {
                        deleteSymbol(tree, position);
                        deleteSymbol(tree, position);
                        deleteSymbol(tree, position);
                        errorPosition = recursiveDescentParse(tokens, tree, position);
                    }
                }
                break;

            case 'T':
                updateTree(tree, 'F', 't', position);
                errorPosition = recursiveDescentParse(tokens, tree, position);
                break;

            case 't':
                updateTree(tree, '*', 'F', 't', position);
                if (recursiveDescentParse(tokens, tree, position) != -1)
                {
                    updateTree(tree, '/', position);
                    if (recursiveDescentParse(tokens, tree, position) != -1)
                    {
                        deleteSymbol(tree, position);
                        deleteSymbol(tree, position);
                        deleteSymbol(tree, position);
                        errorPosition = recursiveDescentParse(tokens, tree, position);
                    }
                }
                break;

            case 'F':
                updateTree(tree, 'N', position);
                if (recursiveDescentParse(tokens, tree, position) != -1)
                {
                    updateTree(tree, '(', 'E', ')', position);
                    errorPosition = recursiveDescentParse(tokens, tree, position);
                }
                break;

            case 'N':
                if (tokensSymbol == 'N')
                {
                    position++;
                    errorPosition = recursiveDescentParse(tokens, tree, position);
                }
                else
                    return position;
                break;

            case '(':
                if (tokensSymbol == '(')
                {
                    position++;
                    errorPosition = recursiveDescentParse(tokens, tree, position);
                }
                else
                    return position;
                break;

            case ')':
                if (tokensSymbol == ')')
                {
                    position++;
                    errorPosition = recursiveDescentParse(tokens, tree, position);
                }
                else
                    return position;
                break;

            case '+':
                if (tokensSymbol == '+')
                {
                    position++;
                    errorPosition = recursiveDescentParse(tokens, tree, position);
                }
                else
                    return position;
                break;

            case '-':
                if (tokensSymbol == '-')
                {
                    position++;
                    errorPosition = recursiveDescentParse(tokens, tree, position);
                }
                else
                    return position;
                break;

            case '*':
                if (tokensSymbol == '*')
                {
                    position++;
                    errorPosition = recursiveDescentParse(tokens, tree, position);
                }
                else
                    return position;
                break;

            case '/':
                if (tokensSymbol == '/')
                {
                    position++;
                    errorPosition = recursiveDescentParse(tokens, tree, position);
                }
                else
                    return position;
                break;
        }
    }

    return errorPosition;
}

int recursiveDescentParse(Line *line)
{
    int i = 0;
    int j = 0;
    Line *tokens = createLine();
    char symbol = 1;

    while (symbol != '\0')
    {
        symbol = getSymbol(line, i);

        if (isOperator(symbol))
            addSymbol(tokens, symbol);

        else if (symbol == '(' || symbol == ')')
            addSymbol(tokens, symbol);

        else
        {
            j = i;
            while (symbol != ' ' && symbol != '\0' && symbol != ')' && !isOperator(symbol))
            {
                i++;
                symbol = getSymbol(line, i);
            }

            if (isFloatNumber(line, j, i))
                addSymbol(tokens, 'N');

            if (symbol == ')')
                addSymbol(tokens, ')');

            if (isOperator(symbol))
                i--;
        }


        i++;
    }

    //printLine(tokens);
    if (isEmpty(tokens))
        return false;

    Line *tree = createLine("E");

    int result = recursiveDescentParse(tokens, tree, 0);

    deleteLine(tree);
    deleteLine(tokens);

    return result;
}

int main()
{
    printf("The program is recursive descent parser.\n");
    const int size = 1000;
    char string[size] = "";

    printf("Enter an expression to be analyzed:\n");
    fgets(string, size, stdin);

    Line *line = createLine(string);

    int result = recursiveDescentParse(line);
    printf(result? "\nCorrect" : "\nIncorrect. Error position: %d", result);

    deleteLine(line);

    return 0;
}

