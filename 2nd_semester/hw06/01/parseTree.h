#pragma once

#include <QString>

class ParseTree
{
public:
    ParseTree();
    void build(QString input);

private:
    class ParseTreeNode
    {
    public:
        ParseTreeNode(QChar newValue, ParseTreeNode *newLeft, ParseTreeNode *newRight);

        QChar value;
        ParseTreeNode *left;
        ParseTreeNode *right;
    };

    ParseTreeNode *root;

    int build(ParseTreeNode *&node, QString input, int position);
};

