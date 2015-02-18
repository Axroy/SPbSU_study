#ifndef BST_H
#define BST_H


struct BSTNode;
struct BST;

BST *createTree();
BSTNode *createTreeNode(int value, BSTNode *left, BSTNode *right);
void insertNode(BST *tree, int value);
void printAscending(BST *tree);
void printDescending(BST *tree);
bool isInTree(BST *tree, int value);
void removeNode(BST *tree, int value);
void printDebug(BST *tree);
void removeTree(BST *tree);


#endif // BST_H
