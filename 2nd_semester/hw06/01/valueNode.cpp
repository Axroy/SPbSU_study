#include "valueNode.h"

ValueNode::ValueNode(int newValue) : value(newValue)
{
}

void ValueNode::print()
{
    std::cout << value;
}

int ValueNode::calculate()
{
    return value;
}

