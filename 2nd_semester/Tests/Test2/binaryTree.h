#pragma once

class BinaryTree
{
public:
    class BinaryTreeNode
    {
    public:
        BinaryTreeNode(int value, BinaryTreeNode *left, BinaryTreeNode *right, BinaryTreeNode *parent);

        int value;
        BinaryTreeNode *left;
        BinaryTreeNode *right;
        BinaryTreeNode *parent;
    };

    BinaryTree();
    ~BinaryTree();
    void insert(int value);
    void remove(int value);
    BinaryTreeNode *getRoot();




    private:
    BinaryTreeNode *root;

    void insert(BinaryTreeNode *&node, int value, BinaryTreeNode *parent);
    void remove(BinaryTreeNode *&node, int value);
    int removeLeftmostNode(BinaryTreeNode *&node);
};

