#include <QCoreApplication>
#include <iostream>
#include <string>

class SomeException{};

class Object1
{
public:
    Object1()
    {
        field = 100500;
    }
    ~Object1()
    {
        std::cout << "Deleted object 1\n";
    }

    int field;
};

class Object2
{
public:
    Object2()
    {
        otherField = "This is a fiiiiield";
    }
    ~Object2()
    {
        std::cout << "Deleted object 2\n";
    }

    std::string otherField;
};


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    try
    {
        Object1 object1;
        Object2 object2;
        throw SomeException();
    }
    catch (SomeException const &)
    {
        std::cout << "Exception catched\n";
    }

    return a.exec();
}
