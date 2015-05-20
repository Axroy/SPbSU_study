#pragma once

class Bag
{
public:
    Bag();
    void insert(int value);

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
};

