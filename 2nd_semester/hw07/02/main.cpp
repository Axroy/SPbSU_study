#include <QCoreApplication>
#include "uniqueList.h"
#include "uniqueListTests.h"

int main(int argc, char *argv[])
{
    UniqueListTests tests;
    QTest::qExec(&tests);

    QCoreApplication a(argc, argv);

    UniqueList *list = new UniqueList;
    if (list->isEmpty())
        printf("!\n");

    list->add(1);
    list->remove(1);
    if (list->isEmpty())
        printf("!!\n");

    return a.exec();
}
