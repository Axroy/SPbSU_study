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
}

UberCalculatorUI::~UberCalculatorUI()
{
    delete digitButtonMapper;
    delete ui;
}

void UberCalculatorUI::onDigitButtonClicked(int digit)
{
    ui->resultField->setText(QString::number(digit));
}
