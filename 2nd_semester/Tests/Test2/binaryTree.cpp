#include "binaryTree.h"

BinaryTree::BinaryTree() : root(nullptr)
{
}

BinaryTree::~BinaryTree()
{
    while (root != nullptr)
        removeLeftmostNode(root);
}

void BinaryTree::insert(int value)
{
    insert(root, value, nullptr);
}

void BinaryTree::remove(int value)
{
    remove(root, value);
}

BinaryTree::BinaryTreeNode *BinaryTree::getRoot()
{
    return root;
}

void BinaryTree::insert(BinaryTreeNode *&node, int value, BinaryTreeNode *parent)
{
    if (node == nullptr)
    {
        node = new BinaryTreeNode(value, nullptr, nullptr, parent);
        return;
    }

    if (node->value < value)
    {
        insert(node->right, value, node);
        return;
    }
    if (node->value > value)
    {
        insert(node->left, value, node);
        return;
    }

    return;
}

void BinaryTree::remove(BinaryTree::BinaryTreeNode *&node, int value)
{
    if (node == nullptr)
        return;

    if (node->value < value)
    {
        remove(node->right, value);
        return;
    }
    if (node->value > value)
    {
        remove(node->left, value);
        return;
    }

    if (node->left == nullptr && node->right == nullptr)
    {
        node = nullptr;
        delete node;
        return;
    }

    if (node->left == nullptr)
    {
        BinaryTreeNode *current = node;
        node = node->right;
        delete current;
        return;
    }

    if (node->right == nullptr)
    {
        BinaryTreeNode *current = node;
        node = node->left;
        delete current;
        return;
    }

    node->value = removeLeftmostNode(node->right);

    return;
}

int BinaryTree::removeLeftmostNode(BinaryTree::BinaryTreeNode *&node)
{
    if (node->left != nullptr)
    {
        removeLeftmostNode(node->left);
    }
    else
    {
        int value = node->value;
        if (node->right != nullptr)
        {
            BinaryTreeNode *current = node;
            node = node->right;
            delete current;
        }
        else
        {
            node = nullptr;
            delete node;
        }

        return value;

    }
}


BinaryTree::BinaryTreeNode::BinaryTreeNode(int value, BinaryTreeNode *left, BinaryTreeNode *right, BinaryTreeNode *parent) :
    value(value), left(left), right(right), parent(parent)
{
}
