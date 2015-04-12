#pragma once

#include <QWidget>
#include <QSignalMapper>

#include "uberCalculator.h"

namespace Ui {
class UberCalculatorUI;
}

class UberCalculatorUI : public QWidget
{
    Q_OBJECT

public:
    explicit UberCalculatorUI(QWidget *parent = 0);
    ~UberCalculatorUI();

private slots:
    void onDigitButtonClicked(int digit);
    void onPointButtonClicked();
    void onOperationButtonClicked(int index);
    void onEqualsButtonClicked();
    void onResetButtonClicked();

private:
    Ui::UberCalculatorUI *ui;
    QSignalMapper *digitButtonMapper;
    QSignalMapper *operationButtonMapper;
    UberCalculator calculator;
};
