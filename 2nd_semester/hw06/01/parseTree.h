#pragma once

#include <QString>

///Class for parse tree.
class ParseTree
{
public:
    ParseTree();
    ~ParseTree();
    ///Builds the tree for certain prefix expression in input.
    void build(QString input);
    ///Prints the tree to console.
    void print();
    ///Counts expression in the tree.
    int count();

    ///Returns true if the trre is empty.
    bool isEmpty();
    ///Returns number of nodes in the tree.
    int getSize();

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
    int size;

    int build(ParseTreeNode *&node, QString input, int position);
};

