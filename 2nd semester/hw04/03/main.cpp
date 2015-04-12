#include "uberCalculatorUI.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    UberCalculatorUI w;
    w.show();

    return a.exec();
}
