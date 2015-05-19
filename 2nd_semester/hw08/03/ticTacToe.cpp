#include "ticTacToe.h"

TicTacToe::TicTacToe(int fieldSize, int winLength) : fieldSize(fieldSize), winLength(winLength)
{
}

bool TicTacToe::checkWin(int coordinateI, int coordinateJ, QPushButton **buttons)
{
    //Column case
    int winCounter = 1;
    int maxCounter = 1;
    int i = coordinateI - 1;
    while (i >= 0 && maxCounter < winLength)
    {
        if (buttons[i][coordinateJ].text() == buttons[coordinateI][coordinateJ].text())
            winCounter++;
        i--;
        maxCounter++;
    }
    i = coordinateI + 1;
    maxCounter = 1;
    while (i < fieldSize && maxCounter < winLength)
    {
        if (buttons[i][coordinateJ].text() == buttons[coordinateI][coordinateJ].text())
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
        if (buttons[coordinateI][j].text() == buttons[coordinateI][coordinateJ].text())
            winCounter++;
        j--;
        maxCounter++;
    }
    j = coordinateJ + 1;
    maxCounter = 1;
    while (j < fieldSize && maxCounter < winLength)
    {
        if (buttons[coordinateI][j].text() == buttons[coordinateI][coordinateJ].text())
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
        if (buttons[i][j].text() == buttons[coordinateI][coordinateJ].text())
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
        if (buttons[i][j].text() == buttons[coordinateI][coordinateJ].text())
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
        if (buttons[i][j].text() == buttons[coordinateI][coordinateJ].text())
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
        if (buttons[i][j].text() == buttons[coordinateI][coordinateJ].text())
            winCounter++;
        i++;
        j--;
        maxCounter++;
    }
    if (winCounter == winLength)
        return true;

    return false;
}

bool TicTacToe::checkDraw(QPushButton **buttons)
{
    for (int i = 0; i < fieldSize; i++)
        for (int j = 0; j < fieldSize; j++)
            if (buttons[i][j].text() == "")
                return false;
    return true;
}

