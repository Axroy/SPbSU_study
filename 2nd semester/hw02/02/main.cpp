#include <iostream>
#include "stack.h"
#include "pointerStack.h"
#include "arrayStack.h"


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

    Stack *arrayExample = new ArrayStack(10);
    arrayExample->push(1);
    arrayExample->push(2);
    arrayExample->push(3);
    arrayExample->push(4);

    arrayExample->print();

    return 0;
}

