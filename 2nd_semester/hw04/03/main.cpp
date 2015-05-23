#include "uberCalculatorUI.h"
#include "uberCalculatorTests.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    UberCalculatorTests tests;
    QTest::qExec(&tests);

    QApplication a(argc, argv);
    UberCalculatorUI w;
    w.show();

    return a.exec();
}
