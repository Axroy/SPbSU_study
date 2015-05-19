#include "ticTacToeUI.h"
#include "ui_ticTacToeUI.h"

TicTacToeUI::TicTacToeUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TicTacToeUI)
{
    ui->setupUi(this);
    fieldSize = 3;
    turn = cross;

    buttons = new QPushButton*[fieldSize];
    for (int i = 0; i < fieldSize; i++)
        buttons[i] = new QPushButton[fieldSize];

    for (int i = 0; i < fieldSize; i++)
        for (int j = 0; j < fieldSize; j++)
        {
            ui->gridLayout->addWidget(&buttons[i][j], i, j);
            buttons[i][j].setMaximumHeight(50);
            buttons[i][j].setMaximumWidth(50);
            ui->gridLayout->setSpacing(0);
        }

    /*for (int i = 0; i < fieldSize; i++)
    {
        ui->gridLayout->setColumnMinimumWidth(i, 30);
        ui->gridLayout->setRowMinimumHeight(i, 30);
    }*/

    buttonMapper = new QSignalMapper(this);
    connect(buttonMapper, SIGNAL(mapped(int)), this, SLOT(onButtonClicked(int)));
    for (int i = 0; i < fieldSize; i++)
        for (int j = 0; j < fieldSize; j++)
        {
            connect(&buttons[i][j], SIGNAL(clicked(bool)), buttonMapper, SLOT(map()));
            buttonMapper->setMapping(&buttons[i][j], fieldSize * i + j);
        }

    for (int i = 0; i < fieldSize; i++)
        for (int j = 0; j < fieldSize; j++)
            buttons[i][j].setText("");

    connect(ui->restartButton, SIGNAL(clicked()), this, SLOT(onRestartButtonClicked()));
}

TicTacToeUI::~TicTacToeUI()
{
    delete ui;
}

void TicTacToeUI::onButtonClicked(int index)
{
    TicTacToe model(fieldSize, fieldSize);

    if (buttons[index / fieldSize][index % fieldSize].text() == "X" ||
            buttons[index / fieldSize][index % fieldSize].text() == "O")
        return;

    switch (turn)
    {
        case cross:
            buttons[index / fieldSize][index % fieldSize].setText("X");
            turn = circle;
            ui->infoLine->setText("Circles' turn");
            break;
        case circle:
            buttons[index / fieldSize][index % fieldSize].setText("O");
            turn = cross;
            ui->infoLine->setText("Crosses' turn");
            break;
    }

    if (model.checkWin(index / fieldSize, index % fieldSize, buttons))
    {
        //The winners are those whose the previous (winning) turn was
        if (turn == cross)
            ui->infoLine->setText("CIRCLES WIN");
        else
            ui->infoLine->setText("CROSSES WIN");
        ui->restartButton->setFocus();

        for (int i = 0; i < fieldSize; i++)
            for (int j = 0; j < fieldSize; j++)
                buttons[i][j].setDisabled(true);

        return;
    }

    if (model.checkDraw(buttons))
    {
        ui->infoLine->setText("DRAW");

        for (int i = 0; i < fieldSize; i++)
            for (int j = 0; j < fieldSize; j++)
                buttons[i][j].setDisabled(true);
    }
}

void TicTacToeUI::onRestartButtonClicked()
{
    for (int i = 0; i < fieldSize; i++)
        for (int j = 0; j < fieldSize; j++)
        {
            buttons[i][j].setText("");
            buttons[i][j].setEnabled(true);
        }

    ui->infoLine->setText("New game: crosses' turn");
}
