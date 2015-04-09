#include "simpleCalculatorUI.h"
#include "ui_simpleCalculator.h"

SimpleCalculatorUI::SimpleCalculatorUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SimpleCalculator)
{
    ui->setupUi(this);
    connect(ui->firstNumber, SIGNAL(valueChanged(int)), this, SLOT(onFirstNumberChanged(int)));
    connect(ui->secondNumber, SIGNAL(valueChanged(int)), this, SLOT(onSecondNumberChanged(int)));
    connect(ui->operation, SIGNAL(currentIndexChanged(int)), this, SLOT(onOperationChanged(int)));
}

SimpleCalculatorUI::~SimpleCalculatorUI()
{
    delete ui;
}

void SimpleCalculatorUI::onFirstNumberChanged(int value)
{
    calculator.changeFirstNumber(value);
    ui->result->setText(QString::number(calculator.getResult()));
}

void SimpleCalculatorUI::onSecondNumberChanged(int value)
{
    calculator.changeSecondNumber(value);
    ui->result->setText(QString::number(calculator.getResult()));
}

void SimpleCalculatorUI::onOperationChanged(int index)
{
    calculator.changeOperation(Operation(index));
    ui->result->setText(QString::number(calculator.getResult()));
}
