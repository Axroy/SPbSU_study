#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include <QApplication>
#include "ticTacToe.h"

class TicTacToeTests : public QObject
{
    Q_OBJECT
public:
    explicit TicTacToeTests(QObject *parent = 0) : QObject(parent) {}

private slots:
    void init()
    {
        fieldSize = 3;
        winLength = 3;
        model = new TicTacToe(fieldSize, winLength);
    }

    void cleanup()
    {
        delete model;
    }

    void columnWinCase()
    {
        model->takeTurn(0, 0, cross);
        model->takeTurn(1, 0, cross);
        model->takeTurn(2, 0, cross);
        QVERIFY(model->checkWin(2, 0));
        model->reset();
    }

    void rowWinCase()
    {
        model->takeTurn(2, 0, circle);
        model->takeTurn(2, 1, circle);
        model->takeTurn(2, 2, circle);
        QVERIFY(model->checkWin(2, 2));
        model->reset();
    }

    void mainDiagonalWinCase()
    {
        model->takeTurn(0, 0, cross);
        model->takeTurn(2, 2, cross);
        model->takeTurn(1, 1, cross);
        QVERIFY(model->checkWin(1, 1));
        model->reset();
    }

    void antiDiagonalWinCase()
    {
        model->takeTurn(2, 0, circle);
        model->takeTurn(1, 1, circle);
        model->takeTurn(0, 2, circle);
        QVERIFY(model->checkWin(0, 2));
        model->reset();
    }

    void differentTurns()
    {
        model->takeTurn(1, 0, circle);
        model->takeTurn(1, 1, cross);
        model->takeTurn(1, 2, circle);
        QVERIFY(!model->checkWin(1, 2));
        model->reset();
    }

private:
    TicTacToe *model;
    int fieldSize;
    int winLength;
};
