#pragma once
#include <QPushButton>

enum Turn
{
    cross,
    circle
};

class TicTacToe
{
public:
    TicTacToe(int fieldSize, int winLength);
    bool checkWin(int coordinateI, int coordinateJ, QPushButton **buttons);
    bool checkDraw(QPushButton **buttons);

private:
    int fieldSize;
    int winLength;
};
