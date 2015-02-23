#include <iostream>
#include "stack.h"
#include "pointerStack.h"


int main()
{
    Stack *example = new PointerStack;
    example->push(1);
    example->push(2);
    example->push(3);
    example->push(4);
    example->push(5);

    example->print();

    delete example;

    return 0;
}

