#pragma once

class SquareArray
{
public:
    SquareArray();
    SquareArray(int arraySize);
    ~SquareArray();
    void print();
    int getSize();
    int element(int i, int j);

private:
    int size;
    int **array;
};

