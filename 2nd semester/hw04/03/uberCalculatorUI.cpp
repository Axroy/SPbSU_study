#include "uberCalculatorUI.h"
#include "ui_uberCalculatorUI.h"

UberCalculatorUI::UberCalculatorUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UberCalculatorUI)
{
    ui->setupUi(this);

    digitButtonMapper = new QSignalMapper(this);
    connect(digitButtonMapper, SIGNAL(mapped(int)), this, SLOT(onDigitButtonClicked(int)));

    digitButtonMapper->setMapping(ui->number0, 0);
    digitButtonMapper->setMapping(ui->number1, 1);
    digitButtonMapper->setMapping(ui->number2, 2);
    digitButtonMapper->setMapping(ui->number3, 3);
    digitButtonMapper->setMapping(ui->number4, 4);
    digitButtonMapper->setMapping(ui->number5, 5);
    digitButtonMapper->setMapping(ui->number6, 6);
    digitButtonMapper->setMapping(ui->number7, 7);
    digitButtonMapper->setMapping(ui->number8, 8);
    digitButtonMapper->setMapping(ui->number9, 9);

    connect(ui->number0, SIGNAL(clicked()), digitButtonMapper, SLOT(map()));
    connect(ui->number1, SIGNAL(clicked()), digitButtonMapper, SLOT(map()));
    connect(ui->number2, SIGNAL(clicked()), digitButtonMapper, SLOT(map()));
    connect(ui->number3, SIGNAL(clicked()), digitButtonMapper, SLOT(map()));
    connect(ui->number4, SIGNAL(clicked()), digitButtonMapper, SLOT(map()));
    connect(ui->number5, SIGNAL(clicked()), digitButtonMapper, SLOT(map()));
    connect(ui->number6, SIGNAL(clicked()), digitButtonMapper, SLOT(map()));
    connect(ui->number7, SIGNAL(clicked()), digitButtonMapper, SLOT(map()));
    connect(ui->number8, SIGNAL(clicked()), digitButtonMapper, SLOT(map()));
    connect(ui->number9, SIGNAL(clicked()), digitButtonMapper, SLOT(map()));


    operationButtonMapper = new QSignalMapper(this);
    connect(operationButtonMapper, SIGNAL(mapped(int)), this, SLOT(onOperationButtonClicked(int)));

    operationButtonMapper->setMapping(ui->plus, (int)plus);
    operationButtonMapper->setMapping(ui->minus, (int)minus);
    operationButtonMapper->setMapping(ui->multiply, (int)multiply);
    operationButtonMapper->setMapping(ui->divide, (int)divide);

    connect(ui->plus, SIGNAL(clicked()), operationButtonMapper, SLOT(map()));
    connect(ui->minus, SIGNAL(clicked()), operationButtonMapper, SLOT(map()));
    connect(ui->multiply, SIGNAL(clicked()), operationButtonMapper, SLOT(map()));
    connect(ui->divide, SIGNAL(clicked()), operationButtonMapper, SLOT(map()));


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

void UberCalculatorUI::onDigitButtonClicked(int digit)
{
    ui->resultField->insert(QString::number(digit));
}

void UberCalculatorUI::onPointButtonClicked()
{
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
