#pragma once

#include <QWidget>
#include <QSignalMapper>

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

private:
    Ui::UberCalculatorUI *ui;
    QSignalMapper *digitButtonMapper;
};
