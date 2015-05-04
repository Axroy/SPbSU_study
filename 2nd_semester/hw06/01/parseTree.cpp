#include "parseTree.h"

ParseTree::ParseTree() : root(nullptr)
{
}

void ParseTree::build(QString input)
{
    build(root, input, 0);
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
