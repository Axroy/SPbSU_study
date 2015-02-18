#include <stdio.h>
#include "parseTree.h"

struct ParseTreeNode
{
    char value;
    ParseTreeNode *left;
    ParseTreeNode *right;
};

struct ParseTree
{
    ParseTreeNode *root;
};


ParseTree *createTree()
{
    ParseTree *tree = new ParseTree;
    tree->root = nullptr;

    return tree;
}

ParseTreeNode *createTreeNode(char value, ParseTreeNode *left, ParseTreeNode *right)
{
    ParseTreeNode *node = new ParseTreeNode;
    node->value = value;
    node->left = left;
    node->right = right;

    return node;
}


int insertExpression(ParseTreeNode *&node, char expression[], int position)
{
    if (expression[position] == '\0')
        return 0;

    if (expression[position] == '(')
        position++;

    node = createTreeNode(expression[position], nullptr, nullptr);

    position = position + 2;
    if (expression[position] == '(')
        position = insertExpression(node->left, expression, position);
    else
        node->left = createTreeNode(expression[position], nullptr, nullptr);

    position = position + 2;
    if (expression[position] == '(')
        position = insertExpression(node->right, expression, position);
    else
        node->right = createTreeNode(expression[position], nullptr, nullptr);

    position++;

    return position;
}

void insertExpression(ParseTree *tree, char expression[])
{
    insertExpression(tree->root, expression, 0);
}


void printPreOrder(ParseTreeNode *node)
{
    if (node == nullptr)
        return;

    if (node->value == '*' || node->value == '/' || node->value == '+' || node->value == '-')
        printf("(");

    if (node->left == nullptr && node->right == nullptr)
    {
        printf("%c", node->value);
        return;
    }
    printPreOrder(node->left);
    printf("%c", node->value);
    printPreOrder(node->right);

    printf(")");

    return;
}

void printPreOrder(ParseTree *tree)
{
    printPreOrder(tree->root);
}


void printDebug(ParseTreeNode *node)
{
    if (node == nullptr)
        return;

    printf("(");

    printf("%c ", node->value);

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

void printDebug(ParseTree *tree)
{
    printDebug(tree->root);
}


void deleteLeftmostNode(ParseTreeNode *&node)
{
    if (node->left != nullptr)
    {
        deleteLeftmostNode(node->left);
    }
    else
    {
        if (node->right != nullptr)
        {
            ParseTreeNode *current = node;
            node = node->right;
            delete current;
        }
        else
        {
            node = nullptr;
            delete node;
        }
    }
}

void removeTree(ParseTree *tree)
{
    while (tree->root != nullptr)
        deleteLeftmostNode(tree->root);
    delete tree;
}


int solveTree(ParseTreeNode *node, int result)
{
    int value1 = 0;
    int value2 = 0;

    if (node->left->value == '+' || node->left->value == '-' || node->left->value == '*' || node->left->value == '/')
        value1 = solveTree(node->left, result);
    else
        value1 = (int)(node->left->value - '0');

    if (node->right->value == '+' || node->right->value == '-' || node->right->value == '*' || node->right->value == '/')
        value2 = solveTree(node->right, result);
    else
        value2 = (int)(node->right->value - '0');

    switch (node->value)
    {
        case '+':
            result = value1 + value2;
            break;
        case '-':
            result = value1 - value2;
            break;
        case '*':
            result = value1 * value2;
            break;
        case '/':
            result = value1 / value2;
            break;
    }

    return result;
}

int solveTree(ParseTree *tree)
{
    return solveTree(tree->root, 0);
}
