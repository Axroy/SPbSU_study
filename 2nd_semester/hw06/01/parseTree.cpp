#include <iostream>
#include "parseTree.h"

ParseTree::ParseTree() : root(nullptr), size(0)
{
}

ParseTree::~ParseTree()
{
    delete root;
}

void ParseTree::build(const QString &input)
{
    build(root, input, 0);
}

void ParseTree::print()
{
    root->print();
    std::cout << "\n";
}

int ParseTree::calculate()
{
    return root->calculate();
}

bool ParseTree::isEmpty()
{
    return size == 0;
}

int ParseTree::getSize()
{
    return size;
}

int ParseTree::build(OperationNode *&node, const QString &input, int position)
{
    if (input.at(position) == '\0')
        return 0;
    if (input.at(position) == '(')
        position++;

    node = new OperationNode(input.at(position), nullptr, nullptr);
    size++;

    position += 2;
    if (input.at(position) == '(')
    {
        OperationNode *leftTree = nullptr;
        position = build(leftTree, input, position);
        node->left = leftTree;
    }
    else
    {
        node->left = new ValueNode((input.at(position).digitValue()));
        size++;
    }

    position += 2;
    if (input.at(position) == '(')
    {
        OperationNode *rightTree = nullptr;
        position = build(rightTree, input, position);
        node->right = rightTree;
    }
    else
    {
        node->right = new ValueNode((input.at(position).digitValue()));
        size++;
    }

    position++;
    return position;
}
