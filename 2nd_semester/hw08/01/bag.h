#pragma once
#include <QString>

class Bag
{
public:
    Bag();
    ~Bag();
    void insert(int value);
    void remove(int value);
    bool exists(int value);
    QString print();
    bool isEmpty();
    int height();

private:
    class AVLTreeNode
    {
    public:
        AVLTreeNode(int value, AVLTreeNode *left, AVLTreeNode *right);
        int balanceFactor();
        int getHeight();
        void updateHeight();
        AVLTreeNode *rotateRight();
        AVLTreeNode *rotateLeft();
        AVLTreeNode *balance();

        int value;
        int height;
        AVLTreeNode *left;
        AVLTreeNode *right;
    };
    AVLTreeNode *root;

    void insert(AVLTreeNode *&node, int value);
    int deleteLeftmostNode(AVLTreeNode *&node);
    int deleteLeftmostNode(AVLTreeNode *&node, AVLTreeNode *parent);
    void remove(AVLTreeNode *&node, int value);
    bool exists(AVLTreeNode *&node, int value);
    QString print(AVLTreeNode *node, QString &string);
};

