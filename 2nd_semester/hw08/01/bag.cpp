#include "bag.h"

Bag::Bag() : root(nullptr)
{
}

void Bag::insert(int value)
{
    insert(root, value);
}

void Bag::insert(Bag::AVLTreeNode *&node, int value)
{
    if (node == nullptr)
    {
        node = new AVLTreeNode(value, nullptr, nullptr);
        return;
    }

    if (node->value < value)
    {
        insert(node->right, value);
        node = node->balance();
        return;
    }
    if (node->value > value)
    {
        insert(node->left, value);
        node = node->balance();
        return;
    }

    return;
}

Bag::AVLTreeNode::AVLTreeNode(int value, Bag::AVLTreeNode *left, Bag::AVLTreeNode *right) : value(value), left(left), right(right)
{
    updateHeight();
}

int Bag::AVLTreeNode::balanceFactor()
{
    return right->getHeight() - left->getHeight();
}

int Bag::AVLTreeNode::getHeight()
{
    if (this == nullptr)
        return 0;
    else
        return height;
}

void Bag::AVLTreeNode::updateHeight()
{
    int heightLeft = left->getHeight();
    int heightRight = right->getHeight();

    if (heightLeft > heightRight)
        height = heightLeft + 1;
    else
        height = heightRight + 1;
}

Bag::AVLTreeNode *Bag::AVLTreeNode::rotateRight()
{
    AVLTreeNode *pivot = left;
    left = pivot->right;
    pivot->right = this;
    updateHeight();
    pivot->updateHeight();

    return pivot;
}

Bag::AVLTreeNode *Bag::AVLTreeNode::rotateLeft()
{
    AVLTreeNode *pivot = right;
    right = pivot->left;
    pivot->left = this;
    updateHeight();
    pivot->updateHeight();

    return pivot;
}

Bag::AVLTreeNode *Bag::AVLTreeNode::balance()
{
    updateHeight();

    if (balanceFactor() == 2)
    {
        if (right->balanceFactor() < 0)
            right = right->rotateRight();

        return rotateLeft();
    }

    if (balanceFactor() == -2)
    {
        if (left->balanceFactor() > 0)
            left = left->rotateLeft();

        return rotateRight();
    }

    return this;
}
