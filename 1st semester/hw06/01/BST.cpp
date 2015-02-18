#include <stdio.h>

struct BSTNode
{
    int value;
    BSTNode *left;
    BSTNode *right;
};

struct BST
{
    BSTNode *root;
};


BST *createTree()
{
    BST *tree = new BST;
    tree->root = nullptr;

    return tree;
}

BSTNode *createTreeNode(int value, BSTNode *left, BSTNode *right)
{
    BSTNode *node = new BSTNode;
    node->value = value;
    node->left = left;
    node->right = right;

    return node;
}


void insertNode(BSTNode *&node, int value)
{
    if (node == nullptr)
    {
        node = createTreeNode(value, nullptr, nullptr);
        return;
    }

    if (node->value < value)
    {
        insertNode(node->right, value);
        return;
    }
    if (node->value > value)
    {
        insertNode(node->left, value);
        return;
    }

    return;
}

void insertNode(BST *tree, int value)
{
    insertNode(tree->root, value);
}


void printAscending(BSTNode *node)
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

void printAscending(BST *tree)
{
    printAscending(tree->root);
}


void printDescending(BSTNode *node)
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

void printDescending(BST *tree)
{
    printDescending(tree->root);
}


bool isInTree(BSTNode *&node, int value)
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

bool isInTree(BST *tree, int value)
{
    return isInTree(tree->root, value);
}

int deleteLeftmostNode(BSTNode *&node)
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
            BSTNode *current = node;
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

void removeNode(BSTNode *&node, int value)
{
    if (node == nullptr)
        return;

    if (node->value < value)
    {
        removeNode(node->right, value);
        return;
    }
    if (node->value > value)
    {
        removeNode(node->left, value);
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
        BSTNode *current = node;
        node = node->right;
        delete current;
        return;
    }

    if (node->right == nullptr)
    {
        BSTNode *current = node;
        node = node->left;
        delete current;
        return;
    }

    node->value = deleteLeftmostNode(node->right);

    return;
}

void removeNode(BST *tree, int value)
{
    removeNode(tree->root, value);
}

void printDebug(BSTNode *node)
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

void printDebug(BST *tree)
{
    printDebug(tree->root);
}

void removeTree(BST *tree)
{
    while (tree->root != nullptr)
        deleteLeftmostNode(tree->root);
    delete tree;
}
