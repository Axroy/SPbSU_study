#pragma once
#include <QPushButton>

///Enumerable for player's turn.
enum Turn
{
    cross,
    circle
};

///Class for checking for draw and win.
class TicTacToe
{
public:
    ///Gets size of field and length of line needed for victory.
    TicTacToe(int fieldSize, int winLength);

    ///Returns true if vicrory is achieved
    ///Gets coordinates of button pressed and array of buttons.
    bool checkWin(int coordinateI, int coordinateJ, QPushButton **buttons);

    ///Returns true if draw is achieved.
    ///Gets array of buttons.
    bool checkDraw(QPushButton **buttons);

private:
    int fieldSize;
    int winLength;
};
