#include <iostream>
#include "parseTree.h"

ParseTree::ParseTree() : root(nullptr)
{
}

ParseTree::~ParseTree()
{
    if (root != nullptr)
        delete root;
}

void ParseTree::build(QString input)
{
    build(root, input, 0);
}

void ParseTree::print()
{
    root->print();
}

int ParseTree::count()
{
    return root->count(0);
}

int ParseTree::build(ParseTreeNode *&node, QString input, int position)
{
    if (input.at(position) == '\0')
        return 0;
    if (input.at(position) == '(')
        position++;

    node = new ParseTreeNode(input.at(position), nullptr, nullptr);

    position += 2;
    if (input.at(position) == '(')
        position = build(node->left, input, position);
    else
        node->left = new ParseTreeNode(input.at(position), nullptr, nullptr);

    position += 2;
    if (input.at(position) == '(')
        position = build(node->right, input, position);
    else
        node->right = new ParseTreeNode(input.at(position), nullptr, nullptr);

    position++;
    return position;
}

ParseTree::ParseTreeNode::ParseTreeNode(QChar newValue, ParseTree::ParseTreeNode *newLeft, ParseTree::ParseTreeNode *newRight)
    : value(newValue), left(newLeft), right(newRight)
{
}

ParseTree::ParseTreeNode::~ParseTreeNode()
{
    if (left != nullptr)
        delete left;
    if (right != nullptr)
        delete right;
}

void ParseTree::ParseTreeNode::print()
{
    if (value == '*' || value == '/' || value == '+' || value == '-')
        printf("(");

    if (left == nullptr && right == nullptr)
    {
        std::cout << value.toLatin1();
        return;
    }
    left->print();
    std::cout << value.toLatin1();
    right->print();

    std::cout << ")";
}

int ParseTree::ParseTreeNode::count(int currentResult)
{
    int value1 = 0;
    int value2 = 0;

    if (left->value == '+' || left->value == '-' || left->value == '*' || left->value == '/')
        value1 = left->count(currentResult);
    else
        value1 = (left->value.digitValue());

    if (right->value == '+' || right->value == '-' || right->value == '*' || right->value == '/')
        value2 = right->count(currentResult);
    else
        value2 = (right->value.digitValue());

    switch (value.toLatin1())
    {
        case '+':
            currentResult = value1 + value2;
            break;
        case '-':
            currentResult = value1 - value2;
            break;
        case '*':
            currentResult = value1 * value2;
            break;
        case '/':
            currentResult = value1 / value2;
            break;
    }

    return currentResult;
}
