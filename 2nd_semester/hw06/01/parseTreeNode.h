#pragma once
#include <QString>
#include <iostream>

///Base class for tree nodes.
class ParseTreeNode
{
public:
    virtual ~ParseTreeNode(){}
    ///Prints node and it's subtree.
    virtual void print() = 0;
    ///Returns result of expression in subtree starting with node.
    virtual int calculate() = 0;
};
