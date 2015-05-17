#include <QCoreApplication>
#include <iostream>
#include "vector.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int *coordinates = new int[10];
    for (int i = 0; i < 10; i++)
        coordinates[i] = i;

    Vector<int> vector1(5, coordinates);
    Vector<int> vector2;

    //vector2 = vector1;

    if (vector1 == vector2)
        std::cout << "equal!";

    Vector<int> vector3 = vector1 + vector2;
    delete[] coordinates;

    return a.exec();
}
