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
    //Column case
    int winCounter = 1;
    int maxCounter = 1;
    int i = coordinateI - 1;
    while (i >= 0 && maxCounter < winLength)
    {
        if (buttons[i][coordinateJ] == buttons[coordinateI][coordinateJ])
            winCounter++;
        i--;
        maxCounter++;
    }
    i = coordinateI + 1;
    maxCounter = 1;
    while (i < fieldSize && maxCounter < winLength)
    {
        if (buttons[i][coordinateJ] == buttons[coordinateI][coordinateJ])
            winCounter++;
        i++;
        maxCounter++;
    }
    if (winCounter == winLength)
        return true;


    //Row case
    winCounter = 1;
    maxCounter = 1;
    int j = coordinateJ - 1;
    while (j >= 0 && maxCounter < winLength)
    {
        if (buttons[coordinateI][j] == buttons[coordinateI][coordinateJ])
            winCounter++;
        j--;
        maxCounter++;
    }
    j = coordinateJ + 1;
    maxCounter = 1;
    while (j < fieldSize && maxCounter < winLength)
    {
        if (buttons[coordinateI][j] == buttons[coordinateI][coordinateJ])
            winCounter++;
        j++;
        maxCounter++;
    }
    if (winCounter == winLength)
        return true;


    //Top left to down right diagonal case
    winCounter = 1;
    maxCounter = 1;
    i = coordinateI - 1;
    j = coordinateJ - 1;
    while (j >= 0 && i >= 0 && maxCounter < winLength)
    {
        if (buttons[i][j] == buttons[coordinateI][coordinateJ])
            winCounter++;
        i--;
        j--;
        maxCounter++;
    }
    i = coordinateI + 1;
    j = coordinateJ + 1;
    maxCounter = 1;
    while (j < fieldSize && i < fieldSize && maxCounter < winLength)
    {
        if (buttons[i][j] == buttons[coordinateI][coordinateJ])
            winCounter++;
        i++;
        j++;
        maxCounter++;
    }
    if (winCounter == winLength)
        return true;


    //Top right to down left diagonal case
    winCounter = 1;
    maxCounter = 1;
    i = coordinateI - 1;
    j = coordinateJ + 1;
    while (j < fieldSize && i >= 0 && maxCounter < winLength)
    {
        if (buttons[i][j] == buttons[coordinateI][coordinateJ])
            winCounter++;
        i--;
        j++;
        maxCounter++;
    }
    i = coordinateI + 1;
    j = coordinateJ - 1;
    maxCounter = 1;
    while (j >= 0 && i < fieldSize && maxCounter < winLength)
    {
        if (buttons[i][j] == buttons[coordinateI][coordinateJ])
            winCounter++;
        i++;
        j--;
        maxCounter++;
    }
    if (winCounter == winLength)
        return true;

    return false;
}

void TicTacToe::reset()
{
    for (int i = 0; i < fieldSize; i++)
        for (int j = 0; j < fieldSize; j++)
            buttons[i][j] = ' ';
}

