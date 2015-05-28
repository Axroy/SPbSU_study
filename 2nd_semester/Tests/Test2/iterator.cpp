#include "iterator.h"

Iterator::Iterator(BinaryTree *tree) : tree(tree), current(tree->getRoot()), previous(nullptr)
{
}

int Iterator::next()
{
    if (current->left != nullptr)
    {
        previous = current;
        current = current->left;
        return previous->value;
    }

    if (current->right != nullptr)
    {
        previous = current;
        current = current->right;
        return previous->value;
    }

    if (current == previous->left)
    {
        BinaryTree::BinaryTreeNode *temp = current;
        current = previous->right;
        previous = temp;
        return previous->value;
    }

    if (current == previous->right)
    {
        BinaryTree::BinaryTreeNode *temp = current;
        current = previous->parent->right;
        previous = temp;
        return previous->value;
    }
}

bool Iterator::isEmpty()
{
    if (previous == nullptr)
        return false;
    return previous->left == nullptr && previous->right == nullptr;
}

void Iterator::reset()
{
    current = tree->getRoot();
}

void Iterator::remove()
{
    next();
    tree->remove(previous->value);
}
