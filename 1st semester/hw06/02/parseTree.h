#ifndef PARSETREE_H
#define PARSETREE_H

struct ParseTreeNode;
struct ParseTree;

ParseTree *createTree();
ParseTreeNode *createTreeNode(char value, ParseTreeNode *left, ParseTreeNode *right);
void insertExpression(ParseTree *tree, char expression[]);
void printPreOrder(ParseTree *tree);
void printDebug(ParseTree *tree);
void removeTree(ParseTree *tree);
int solveTree(ParseTree *tree);

#endif // PARSETREE_H
