#include "simpleCalculatorUI.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SimpleCalculatorUI w;
    w.show();

    return a.exec();
}
