#pragma once

#include "parseTreeNode.h"

///Class for tree nodes with values.
class ValueNode : public ParseTreeNode
{
public:
    ValueNode(int newValue);
    void print();
    int calculate();

private:
    int value;
};

