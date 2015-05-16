#pragma once

///A class for comfortable work with square arrays
class SquareArray
{
public:
    ///Default constructor
    SquareArray();
    ///Constructor with manual array size
    SquareArray(int arraySize);
    ///Makes SquareArray from standard int[][].
    SquareArray(int **stdArray, int arraySize);
    ///Destructor
    ~SquareArray();
    ///Prints an array to console
    void print();
    ///Returns size of array
    int getSize();
    ///Return value of element with indexes i and j
    int element(int i, int j);

private:
    int size;
    int **array;
};

