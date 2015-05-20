#include <QCoreApplication>
#include "bag.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Bag *bag = new Bag();
    for (int i = 0; i < 10; i++)
        bag->insert(i);

    return a.exec();
}
