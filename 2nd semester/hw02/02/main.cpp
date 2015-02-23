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

    std::cout << "\n\n" << example->pop();
    std::cout << " " << example->pop();

    std::cout << "\n\n";
    example->print();

    delete example;

    return 0;
}

