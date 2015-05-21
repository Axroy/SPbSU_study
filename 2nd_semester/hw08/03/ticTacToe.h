#pragma once
#include <QPushButton>

///Enumerable for player's turn.
enum Turn
{
    cross,
    circle
};

///Class used for checking for win.
class TicTacToe
{
public:
    ///Gets size of field and length of line needed for victory.
    TicTacToe(int fieldSize, int winLength);

    ///Returns true if vicrory is achieved
    ///Gets coordinates of button pressed and array of buttons.
    bool checkWin(int coordinateI, int coordinateJ, QPushButton **buttons);

private:
    int fieldSize;
    int winLength;
};
