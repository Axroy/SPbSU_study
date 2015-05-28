#pragma once
#include <QChar>

///Enumerable for player's turn.
enum Turn
{
    cross,
    circle
};

enum Bypass
{
    row,
    column,
    mainDiagonal,
    antiDiagonal
};

///Class used for checking for win.
class TicTacToe
{
public:
    ///Gets size of field and length of line needed for victory.
    TicTacToe(int fieldSize, int winLength);

    ~TicTacToe();

    ///Sets X or O to place with given coordinates.
    void takeTurn(int coordinateI, int coordinateJ, Turn turn);

    ///Returns true if vicrory is achieved
    ///Gets coordinates of button pressed and array of buttons.
    bool checkWin(int coordinateI, int coordinateJ);

    ///Sets game to starting state.
    void reset();

private:
    bool lineCheck(int coordinateI, int coordinateJ, Bypass bypass);

    QChar** buttons;
    int fieldSize;
    int winLength;
};
