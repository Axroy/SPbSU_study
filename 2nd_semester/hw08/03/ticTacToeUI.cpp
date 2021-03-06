#include "ticTacToeUI.h"
#include "ui_ticTacToeUI.h"

TicTacToeUI::TicTacToeUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TicTacToeUI)
{
    ui->setupUi(this);
    fieldSize = 8;
    winLength = 4;
    model = new TicTacToe(fieldSize, winLength);
    turn = cross;
    emptyButtons = fieldSize * fieldSize;

    buttons = new QPushButton*[fieldSize];
    for (int i = 0; i < fieldSize; i++)
        buttons[i] = new QPushButton[fieldSize];

    for (int i = 0; i < fieldSize; i++)
        for (int j = 0; j < fieldSize; j++)
        {
            ui->gridLayout->addWidget(&buttons[i][j], i, j);
            buttons[i][j].setMaximumHeight(100);
            buttons[i][j].setMaximumWidth(100);
        }


    buttonMapper = new QSignalMapper(this);
    connect(buttonMapper, SIGNAL(mapped(int)), this, SLOT(onButtonClicked(int)));
    for (int i = 0; i < fieldSize; i++)
        for (int j = 0; j < fieldSize; j++)
        {
            connect(&buttons[i][j], SIGNAL(clicked(bool)), buttonMapper, SLOT(map()));
            buttonMapper->setMapping(&buttons[i][j], fieldSize * i + j);
        }

    QFont font = buttons[0][0].font();
    font.setPointSize(16);
    for (int i = 0; i < fieldSize; i++)
        for (int j = 0; j < fieldSize; j++)
        {
            buttons[i][j].setFont(font);
            buttons[i][j].setText(" ");
        }

    connect(ui->restartButton, SIGNAL(clicked()), this, SLOT(onRestartButtonClicked()));

    ui->centralWidget->setFocus();
}


TicTacToeUI::~TicTacToeUI()
{
    delete ui;
}

void TicTacToeUI::disableGameButtons()
{
    for (int i = 0; i < fieldSize; i++)
        for (int j = 0; j < fieldSize; j++)
            buttons[i][j].setDisabled(true);
}

void TicTacToeUI::enableGameButtons()
{
    for (int i = 0; i < fieldSize; i++)
        for (int j = 0; j < fieldSize; j++)
            buttons[i][j].setEnabled(true);
}

bool TicTacToeUI::checkDraw()
{
    return emptyButtons == 0;
}

void TicTacToeUI::onButtonClicked(int index)
{
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
    model->takeTurn(index / fieldSize, index % fieldSize, turn);
    emptyButtons--;

    if (model->checkWin(index / fieldSize, index % fieldSize))
    {
        //The winners are those whose the previous (winning) turn was
        if (turn == cross)
            ui->infoLine->setText("CIRCLES WIN");
        else
            ui->infoLine->setText("CROSSES WIN");
        ui->restartButton->setFocus();

        disableGameButtons();

        return;
    }

    if (checkDraw())
    {
        ui->infoLine->setText("DRAW");
        ui->restartButton->setFocus();

        disableGameButtons();
    }
}

void TicTacToeUI::onRestartButtonClicked()
{
    model->reset();
    turn = cross;
    emptyButtons = fieldSize *fieldSize;
    enableGameButtons();
    for (int i = 0; i < fieldSize; i++)
        for (int j = 0; j < fieldSize; j++)
            buttons[i][j].setText(" ");

    ui->infoLine->setText("New game: crosses' turn");
}
