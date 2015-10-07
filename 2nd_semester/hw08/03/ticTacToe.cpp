#include "ticTacToe.h"

TicTacToe::TicTacToe(int fieldSize, int winLength) : fieldSize(fieldSize), winLength(winLength)
{
    buttons = new QChar*[fieldSize];
    for (int i = 0; i < fieldSize; i++)
        buttons[i] = new QChar[fieldSize];

    for (int i = 0; i < fieldSize; i++)
        for (int j = 0; j < fieldSize; j++)
            buttons[i][j] = ' ';
}

TicTacToe::~TicTacToe()
{
    for (int i = 0; i < fieldSize; i++)
        delete[] buttons[i];
    delete[] buttons;
}

void TicTacToe::takeTurn(int coordinateI, int coordinateJ, Turn turn)
{
    if (turn == cross)
        buttons[coordinateI][coordinateJ] = 'X';
    else
        buttons[coordinateI][coordinateJ] = 'O';
}

bool TicTacToe::checkWin(int coordinateI, int coordinateJ)
{
    if (buttons[coordinateI][coordinateJ] == ' ')
        return false;

    return (lineCheck(coordinateI, coordinateJ, column)
            || lineCheck(coordinateI, coordinateJ, row)
            || lineCheck(coordinateI, coordinateJ, mainDiagonal)
            || lineCheck(coordinateI, coordinateJ, antiDiagonal));
}

void TicTacToe::reset()
{
    for (int i = 0; i < fieldSize; i++)
        for (int j = 0; j < fieldSize; j++)
            buttons[i][j] = ' ';
}

bool TicTacToe::lineCheck(int coordinateI, int coordinateJ, Bypass bypass)
{
    //Don't know how to name these.
    //They are needed to specify bypass.
    int x = 0;
    int y = 0;
    switch (bypass)
    {
        case row:
            x = 1;
            y = 0;
        break;

        case column:
            x = 0;
            y = 1;
        break;

        case mainDiagonal:
            x = 1;
            y = 1;
        break;

        case antiDiagonal:
            x = -1;
            y = 1;
            break;
    }

    int winCounter = 0;
    int i = 0;
    int j = 0;
    for (int k = -winLength; k <= winLength; k++)
    {
        i = y * k + coordinateI;
        j = x * k + coordinateJ;
        if (i < 0 || i >= fieldSize || j < 0 || j >= fieldSize)
            continue;
        if (buttons[i][j] == buttons[coordinateI][coordinateJ])
            winCounter++;
        else
            winCounter = 0;

        if (winCounter == winLength)
            return true;
    }
    return false;
}

