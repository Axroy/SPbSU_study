#pragma once

#include <QWidget>
#include "simpleCalculator.h"

namespace Ui {
class SimpleCalculator;
}

class SimpleCalculatorUI : public QWidget
{
    Q_OBJECT

public:
    explicit SimpleCalculatorUI(QWidget *parent = 0);
    ~SimpleCalculatorUI();

private slots:
    void onFirstNumberChanged(int value);
    void onSecondNumberChanged(int value);
    void onOperationChanged(int value);

private:
    Ui::SimpleCalculator *ui;
    SimpleCalculator calculator;
};
