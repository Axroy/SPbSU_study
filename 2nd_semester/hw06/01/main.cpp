#include <QCoreApplication>
#include "parseTree.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    ParseTree *tree = new ParseTree();
    tree->build("(* (+ 1 1) 2)");

    return a.exec();
}
