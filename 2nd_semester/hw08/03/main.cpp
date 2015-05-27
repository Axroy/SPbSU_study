#include "ticTacToeUI.h"
#include "ticTacToeTests.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    TicTacToeTests tests;
    QTest::qExec(&tests);

    QApplication a(argc, argv);
    TicTacToeUI w;
    w.show();

    return a.exec();
}
