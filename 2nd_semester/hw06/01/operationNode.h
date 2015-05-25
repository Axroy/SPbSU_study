#pragma once

#include "parseTreeNode.h"

///Classs for tree nodes with operations.
class OperationNode : public ParseTreeNode
{
public:
    OperationNode(QChar newOperation, ParseTreeNode *newLeft, ParseTreeNode *newRight);
    void print();
    int calculate();

    ParseTreeNode *left;
    ParseTreeNode *right;

private:
    QChar operation;
};

