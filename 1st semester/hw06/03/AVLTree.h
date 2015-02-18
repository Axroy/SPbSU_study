#ifndef AVLTREE_H
#define AVLTREE_H


struct AVLTreeNode;
struct AVLTree;

AVLTree *createTree();
AVLTreeNode *createTreeNode(int value, AVLTreeNode *left, AVLTreeNode *right);
void insertNode(AVLTree *tree, int value);
void printAscending(AVLTree *tree);
void printDescending(AVLTree *tree);
bool isInTree(AVLTree *tree, int value);
void removeNode(AVLTree *tree, int value);
void printDebug(AVLTree *tree);
void removeTree(AVLTree *tree);


#endif // AVLTREE_H
