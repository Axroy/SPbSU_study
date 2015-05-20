#pragma once
#include <QString>

///Class representing set with possibility of repeating elements.
///Based on the AVL tree.
class Bag
{
public:
    Bag();
    ~Bag();
    ///Adds value to the bag.
    void insert(int value);
    ///Removes value from the bag.
    void remove(int value);
    ///Returns true if a value exists in the bag.
    bool exists(int value);
    ///Returns string with structure of bag in following
    ///representation: (value left_subtree right_subtree).
    QString print();
    ///Returns true if the bag contains no elements.
    bool isEmpty();
    ///Returns number of levels in tree.
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

