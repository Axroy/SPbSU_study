#pragma once

#include <QString>

class ParseTree
{
public:
    ParseTree();
    ~ParseTree();
    void build(QString input);
    void print();
    int count();

private:
    class ParseTreeNode
    {
    public:
        ParseTreeNode(QChar newValue, ParseTreeNode *newLeft, ParseTreeNode *newRight);
        ~ParseTreeNode();

        QChar value;
        ParseTreeNode *left;
        ParseTreeNode *right;

        void print();
        int count(int currentResult);
    };

    ParseTreeNode *root;

    int build(ParseTreeNode *&node, QString input, int position);
};

