#include "simpleCalculatorUI.h"
#include "ui_simpleCalculator.h"

SimpleCalculatorUI::SimpleCalculatorUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SimpleCalculator)
{
    ui->setupUi(this);
    connect(ui->firstNumber, SIGNAL(valueChanged(int)), this, SLOT(onFirstNumberChanged(int)));
}

SimpleCalculatorUI::~SimpleCalculatorUI()
{
    delete ui;
}

void SimpleCalculatorUI::onFirstNumberChanged(int value)
{
    //calculator.changeFirstNumber(value);
    ui->result->setText(QVariant(calculator.getResult()).toString());
}

void SimpleCalculatorUI::onSecondNumberChanged(int value)
{

}

void SimpleCalculatorUI::onOperationChanged(int value)
{

}
