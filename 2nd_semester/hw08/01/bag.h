#pragma once
#include "AVLTree.h"

///Class representing set with possibility of repeating elements.
///Based on the AVL tree.
class Bag
{
public:
    Bag() : tree(new AVLTree){}
    ~Bag()
    {
        delete tree;
    }
    ///Adds value to the bag.
    void insert(int value)
    {
        tree->insert(value);
    }
    ///Removes value from the bag.
    void remove(int value)
    {
        tree->remove(value);
    }
    ///Returns true if a value exists in the bag.
    bool exists(int value)
    {
        return tree->exists(value);
    }
    ///Returns string with structure of bag in following
    ///representation: (value left_subtree right_subtree).
    QString print()
    {
        return tree->print();
    }
    ///Returns true if the bag contains no elements.
    bool isEmpty()
    {
        return tree->isEmpty();
    }

private:
    AVLTree *tree;
};
