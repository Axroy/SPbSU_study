#include "AVLTree.h"

AVLTree::AVLTree() : root(nullptr)
{
}

AVLTree::~AVLTree()
{
    while (root != nullptr)
        deleteLeftmostNode(root);
}

void AVLTree::insert(int value)
{
    insert(root, value);
}

void AVLTree::remove(int value)
{
    remove(root, value);
}

bool AVLTree::exists(int value)
{
    return exists(root, value);
}

QString AVLTree::print()
{
    QString result = "";
    return print(root, result).trimmed();
}

QString AVLTree::print(AVLTreeNode *node, QString &string)
{
    if (node == nullptr)
        return string;

    string += "(";

    string += QString::number(node->value);
    string += " ";

    if (node->left == nullptr)
        string += "null ";
    else
        print(node->left, string);

    if (node->right == nullptr)
        string += "null";
    else
        print(node->right, string);

    string += ") ";

    return string;
}

bool AVLTree::isEmpty()
{
    return root == nullptr;
}

int AVLTree::height()
{
    return root->height;
}

void AVLTree::insert(AVLTree::AVLTreeNode *&node, int value)
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

int AVLTree::deleteLeftmostNode(AVLTree::AVLTreeNode *&node)
{
    if (node->left != nullptr)
    {
        deleteLeftmostNode(node->left);
    }
    else
    {
        int value = node->value;
        if (node->right != nullptr)
        {
            AVLTreeNode *current = node;
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
    return 0;
}

int AVLTree::deleteLeftmostNode(AVLTree::AVLTreeNode *&node, AVLTree::AVLTreeNode *parent)
{
    if (node->left != nullptr)
    {
        deleteLeftmostNode(node->left, node);
    }
    else
    {
        int value = node->value;
        if (node->right != nullptr)
        {
            AVLTreeNode *current = node;
            node = node->right;
            delete current;
        }
        else
        {
            node = nullptr;
            delete node;
        }

        parent = parent->balance();

        return value;
    }
    return 0;
}

void AVLTree::remove(AVLTree::AVLTreeNode *&node, int value)
{
    if (node == nullptr)
        return;

    if (node->value < value)
    {
        remove(node->right, value);
        node = node->balance();
        return;
    }
    if (node->value > value)
    {
        remove(node->left, value);
        node = node->balance();
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
        AVLTreeNode *current = node;
        node = node->right;
        delete current;
        return;
    }

    if (node->right == nullptr)
    {
        AVLTreeNode *current = node;
        node = node->left;
        delete current;
        return;
    }

    node->value = deleteLeftmostNode(node->right);

    return;
}

bool AVLTree::exists(AVLTree::AVLTreeNode *&node, int value)
{
    if (node == nullptr)
        return false;

    if (node->value == value)
        return true;
    if (node->value < value)
        return exists(node->right, value);
    if (node->value > value)
        return exists(node->left, value);

    return false;
}

AVLTree::AVLTreeNode::AVLTreeNode(int value, AVLTree::AVLTreeNode *left, AVLTree::AVLTreeNode *right) : value(value), left(left), right(right)
{
    updateHeight();
}

int AVLTree::AVLTreeNode::balanceFactor()
{
    return right->getHeight() - left->getHeight();
}

int AVLTree::AVLTreeNode::getHeight()
{
    if (this == nullptr)
        return 0;
    else
        return height;
}

void AVLTree::AVLTreeNode::updateHeight()
{
    int heightLeft = left->getHeight();
    int heightRight = right->getHeight();

    if (heightLeft > heightRight)
        height = heightLeft + 1;
    else
        height = heightRight + 1;
}

AVLTree::AVLTreeNode *AVLTree::AVLTreeNode::rotateRight()
{
    AVLTreeNode *pivot = left;
    left = pivot->right;
    pivot->right = this;
    updateHeight();
    pivot->updateHeight();

    return pivot;
}

AVLTree::AVLTreeNode *AVLTree::AVLTreeNode::rotateLeft()
{
    AVLTreeNode *pivot = right;
    right = pivot->left;
    pivot->left = this;
    updateHeight();
    pivot->updateHeight();

    return pivot;
}

AVLTree::AVLTreeNode *AVLTree::AVLTreeNode::balance()
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
