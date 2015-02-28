#pragma once

class SquareArray
{
public:
    SquareArray();
    SquareArray(int arraySize);
    ~SquareArray();
    void print();
    int getSize();

private:
    int size;
    int **array;
};

