#include "operationNode.h"

OperationNode::OperationNode(QChar newOperation, ParseTreeNode *newLeft, ParseTreeNode *newRight) :
    left(newLeft), right(newRight), operation(newOperation)
{
}

void OperationNode::print()
{
    std::cout << "(";
    left->print();
    std::cout << operation.toLatin1();
    right->print();
    std::cout << ")";
}

int OperationNode::calculate()
{
    switch (operation.toLatin1())
    {
        case '+':
            return left->calculate() + right->calculate();
            break;

        case '-':
            return left->calculate() - right->calculate();
            break;

        case '*':
            return left->calculate() * right->calculate();
            break;

        case '/':
            return left->calculate() / right->calculate();
            break;
    }
    return 0;
}

