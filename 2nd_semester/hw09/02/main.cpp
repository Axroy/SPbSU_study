#include "quotesBrowser.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QuotesBrowser w;
    w.show();

    return a.exec();
}
