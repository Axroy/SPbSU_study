#include <stdio.h>
#include "AVLTree.h"

struct AVLTreeNode
{
    int value;
    int height;
    AVLTreeNode *left;
    AVLTreeNode *right;
};

struct AVLTree
{
    AVLTreeNode *root;
};


int height(AVLTreeNode *node)
{
   return node ? node->height : 0;
}

int balanceFactor(AVLTreeNode *node)
{
   return height(node->right) - height(node->left);
}

void updateHeight(AVLTreeNode *node)
{
   int heightLeft = height(node->left);
   int heightRight = height(node->right);
   node->height = ((heightLeft > heightRight) ? heightLeft : heightRight) + 1;
}

AVLTreeNode *rotateRight(AVLTreeNode *root)
{
   AVLTreeNode *pivot = root->left;
   root->left = pivot->right;
   pivot->right = root;
   updateHeight(root);
   updateHeight(pivot);

   return pivot;
}

AVLTreeNode *rotateLeft(AVLTreeNode *root)
{
   AVLTreeNode *pivot = root->right;
   root->right = pivot->left;
   pivot->left = root;
   updateHeight(root);
   updateHeight(pivot);

   return pivot;
}

AVLTreeNode *balance(AVLTreeNode *node)
{
    updateHeight(node);

    if (balanceFactor(node) == 2)
    {
        if (balanceFactor(node->right) < 0)
            node->right = rotateRight(node->right);

        return rotateLeft(node);
    }

    if (balanceFactor(node) == -2)
    {
        if (balanceFactor(node->left) > 0)
            node->left = rotateLeft(node->left);

        return rotateRight(node);
    }

    return node;
}

AVLTree *createTree()
{
    AVLTree *tree = new AVLTree;
    tree->root = nullptr;

    return tree;
}

AVLTreeNode *createTreeNode(int value, AVLTreeNode *left, AVLTreeNode *right)
{
    AVLTreeNode *node = new AVLTreeNode;
    node->value = value;
    node->left = left;
    node->right = right;
    updateHeight(node);

    return node;
}


void insertNode(AVLTreeNode *&node, int value)
{
    if (node == nullptr)
    {
        node = createTreeNode(value, nullptr, nullptr);
        return;
    }

    if (node->value < value)
    {
        insertNode(node->right, value);
        node = balance(node);
        return;
    }
    if (node->value > value)
    {
        insertNode(node->left, value);
        node = balance(node);
        return;
    }

    return;
}

void insertNode(AVLTree *tree, int value)
{
    insertNode(tree->root, value);
}


void printAscending(AVLTreeNode *node)
{
    if (node == nullptr)
        return;

    if (node->left == nullptr && node->right == nullptr)
    {
        printf("%d ", node->value);
        return;
    }
    printAscending(node->left);
    printf("%d ", node->value);
    printAscending(node->right);

    return;
}

void printAscending(AVLTree *tree)
{
    printAscending(tree->root);
}


void printDescending(AVLTreeNode *node)
{
    if (node == nullptr)
        return;

    if (node->left == nullptr && node->right == nullptr)
    {
        printf("%d ", node->value);
        return;
    }
    printDescending(node->right);
    printf("%d ", node->value);
    printDescending(node->left);

    return;
}

void printDescending(AVLTree *tree)
{
    printDescending(tree->root);
}


bool isInTree(AVLTreeNode *&node, int value)
{
    if (node == nullptr)
        return false;

    if (node->value == value)
        return true;
    if (node->value < value)
        return isInTree(node->right, value);
    if (node->value > value)
        return isInTree(node->left, value);

    return false;
}

bool isInTree(AVLTree *tree, int value)
{
    return isInTree(tree->root, value);
}

int deleteLeftmostNode(AVLTreeNode *&node)
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
}

int deleteLeftmostNode(AVLTreeNode *&node, AVLTreeNode *parent)
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

        parent = balance(parent);

        return value;
    }
}

void removeNode(AVLTreeNode *&node, int value)
{
    if (node == nullptr)
        return;

    if (node->value < value)
    {
        removeNode(node->right, value);
        node = balance(node);
        return;
    }
    if (node->value > value)
    {
        removeNode(node->left, value);
        node = balance(node);
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

void removeNode(AVLTree *tree, int value)
{
    removeNode(tree->root, value);
}

void printDebug(AVLTreeNode *node)
{
    if (node == nullptr)
        return;

    printf("(");

    printf("%d ", node->value);

    if (node->left == nullptr)
        printf("null ");
    else
        printDebug(node->left);

    if (node->right == nullptr)
        printf("null");
    else
        printDebug(node->right);

    printf(")");
}

void printDebug(AVLTree *tree)
{
    printDebug(tree->root);
}

void removeTree(AVLTree *tree)
{
    while (tree->root != nullptr)
        deleteLeftmostNode(tree->root);
    delete tree;
}
