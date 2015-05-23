#include "uberCalculatorUI.h"
#include "ui_uberCalculatorUI.h"

UberCalculatorUI::UberCalculatorUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UberCalculatorUI)
{
    ui->setupUi(this);

    digitButtonMapper = new QSignalMapper(this);
    connect(digitButtonMapper, SIGNAL(mapped(int)), this, SLOT(onDigitButtonClicked(int)));

    connectButtonToMapper(digitButtonMapper, ui->number0, 0);
    connectButtonToMapper(digitButtonMapper, ui->number1, 1);
    connectButtonToMapper(digitButtonMapper, ui->number2, 2);
    connectButtonToMapper(digitButtonMapper, ui->number3, 3);
    connectButtonToMapper(digitButtonMapper, ui->number4, 4);
    connectButtonToMapper(digitButtonMapper, ui->number5, 5);
    connectButtonToMapper(digitButtonMapper, ui->number6, 6);
    connectButtonToMapper(digitButtonMapper, ui->number7, 7);
    connectButtonToMapper(digitButtonMapper, ui->number8, 8);
    connectButtonToMapper(digitButtonMapper, ui->number9, 9);


    operationButtonMapper = new QSignalMapper(this);
    connect(operationButtonMapper, SIGNAL(mapped(int)), this, SLOT(onOperationButtonClicked(int)));

    connectButtonToMapper(operationButtonMapper, ui->plus, (int)plus);
    connectButtonToMapper(operationButtonMapper, ui->minus, (int)minus);
    connectButtonToMapper(operationButtonMapper, ui->multiply, (int)multiply);
    connectButtonToMapper(operationButtonMapper, ui->divide, (int)divide);


    connect(ui->point, SIGNAL(clicked()), this, SLOT(onPointButtonClicked()));
    connect(ui->equals, SIGNAL(clicked()), this, SLOT(onEqualsButtonClicked()));
    connect(ui->reset, SIGNAL(clicked()), this, SLOT(onResetButtonClicked()));
}

UberCalculatorUI::~UberCalculatorUI()
{
    delete digitButtonMapper;
    delete operationButtonMapper;
    delete ui;
}

void UberCalculatorUI::connectButtonToMapper(QSignalMapper *mapper, QPushButton *button, int value)
{
    connect(button, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(button, value);
}

void UberCalculatorUI::onDigitButtonClicked(int digit)
{
    ui->resultField->insert(QString::number(digit));
}

void UberCalculatorUI::onPointButtonClicked()
{
    if (ui->resultField->text().right(1) != ".")
        ui->resultField->insert(".");
}

void UberCalculatorUI::onOperationButtonClicked(int index)
{
    if (calculator.hasNoOperation())
    {
        calculator.changeFirstArgument(ui->resultField->text().toFloat());
        calculator.changeOperation((Operation)index);
        ui->resultField->clear();
    }
    else
    {
        calculator.changeSecondArgument(ui->resultField->text().toFloat());
        calculator.changeFirstArgument(calculator.getResult());
        calculator.changeOperation((Operation)index);
        ui->resultField->clear();
    }
}

void UberCalculatorUI::onEqualsButtonClicked()
{
    if (calculator.hasNoOperation())
        return;
    calculator.changeSecondArgument(ui->resultField->text().toFloat());
    ui->resultField->setText(QString::number(calculator.getResult()));
    calculator.reset();
}

void UberCalculatorUI::onResetButtonClicked()
{
    ui->resultField->clear();
    calculator.reset();
}
