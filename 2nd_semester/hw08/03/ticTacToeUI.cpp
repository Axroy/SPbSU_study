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
            ui->gridLayout->addWidget(&buttons[i][j], i, j);

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
}

TicTacToeUI::~TicTacToeUI()
{
    delete ui;
}

void TicTacToeUI::onButtonClicked(int index)
{
    switch (turn)
    {
        case cross:
            buttons[index / fieldSize][index % fieldSize].setText("X");
            buttons[index / fieldSize][index % fieldSize].setDisabled(true);
            turn = circle;
            ui->lineEdit->setText("Circles' turn");
            break;
        case circle:
            buttons[index / fieldSize][index % fieldSize].setText("O");
            buttons[index / fieldSize][index % fieldSize].setDisabled(true);
            turn = cross;
            ui->lineEdit->setText("Crosses' turn");
            break;
    }
}
