#include <fstream>
#include <QString>
#include "counter.h"
#include "parseTree.h"


int Counter::countExpression(const std::string &fileName)
{
    std::ifstream file(fileName);
    if (file == nullptr)
        return 0;

    std::string input;
    std::getline(file, input);
    file.close();

    ParseTree *tree = new ParseTree;
    tree->build(QString::fromStdString(input));
    int result = tree->count();
    delete tree;
    return result;
}

