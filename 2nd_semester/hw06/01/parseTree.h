#pragma once

#include <QString>

#include "parseTreeNode.h"
#include "operationNode.h"
#include "valueNode.h"

///Class for parse tree.
class ParseTree
{
public:
    ParseTree();
    ~ParseTree();
    ///Builds the tree for certain prefix expression in input.
    void build(const QString &input);
    ///Prints the tree to console.
    void print();
    ///Calculates expression in the tree.
    int calculate();

    ///Returns true if the tree is empty.
    bool isEmpty();
    ///Returns number of nodes in the tree.
    int getSize();

private:
    OperationNode *root;
    int size;

    int build(OperationNode *&node, const QString &input, int position);
};
