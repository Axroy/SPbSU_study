#pragma once
#include <QMainWindow>
#include <QSignalMapper>
#include <QPushButton>
#include "ticTacToe.h"

namespace Ui {
class TicTacToeUI;
}

class TicTacToeUI : public QMainWindow
{
    Q_OBJECT

public:
    explicit TicTacToeUI(QWidget *parent = 0);
    ~TicTacToeUI();

private:
    void disableGameButtons();
    void enableGameButtons();

    Ui::TicTacToeUI *ui;
    QSignalMapper *buttonMapper;
    QPushButton **buttons;
    Turn turn;
    int fieldSize;
    int winLength;

private slots:
    void onButtonClicked(int index);
    void onRestartButtonClicked();
};

