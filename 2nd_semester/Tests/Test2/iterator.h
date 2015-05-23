#pragma once

#include "binaryTree.h"

///Class for parsing binary trees.
class Iterator
{
public:
    Iterator(BinaryTree *tree);
    ///Returns value of current element and goes to the next one.
    int next();
    ///Returns true if last called next() function returned last element in tree.
    bool isEmpty();
    ///Returns iterator to root.
    void reset();
    ///Removes current element and goes to next one.
    void remove();

private:
    BinaryTree *tree;
    BinaryTree::BinaryTreeNode *current;
    BinaryTree::BinaryTreeNode *previous;
};
