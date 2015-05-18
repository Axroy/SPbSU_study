#pragma once

///An exception thrown when two vectors have different sizes.
class DifferentSizes{};

///Template class for vectors.
template <typename T>
class Vector
{
public:
    ///Creates vector with default size (current = 10) and null coordinates.
    Vector();

    ///Creates vector with certain size and coordinates.
    Vector(int size, T *values);

    ///Creates new vector equal to given.
    Vector(const Vector<T> &vector);

    ~Vector();

    ///Redefinition of different operators which can be used with vectors.
    Vector<T> operator+ (const Vector<T> &vector)throw (DifferentSizes);
    Vector<T> operator- (const Vector<T> &vector)throw (DifferentSizes);
    Vector<T> operator* (const T &scalar);
    Vector<T> operator= (const Vector<T> &vector);
    bool operator== (const Vector<T> &vector);

    ///Returns true if all coordinates = 0.
    bool isNull();

    ///Returns coordinate from certain position.
    T at(int position);

    ///Returns size of a vector.
    int getSize();

private:
    int size;
    T *coordinates;
};


template <typename T>
Vector<T>::Vector() : size(10), coordinates(new T[size])
{
    for (int i = 0; i < size; i++)
        coordinates[i] = 0;
}

template <typename T>
Vector<T>::Vector(int size, T *values) : size(size), coordinates(new T[size])
{
    for (int i = 0; i < size; i++)
        coordinates[i] = values[i];
}

template <typename T>
Vector<T>::Vector(const Vector<T> &vector) : size(vector.size), coordinates(new T[size])
{
    for (int i = 0; i < size; i++)
        coordinates[i] = vector.coordinates[i];
}

template <typename T>
Vector<T>::~Vector()
{
    delete[] coordinates;
}

template <typename T>
Vector<T> Vector<T>::operator+(const Vector<T> &vector)throw (DifferentSizes)
{
    if (size != vector.size)
        throw DifferentSizes();

    T *resultCoordinates = new T[size];
    for (int i = 0; i < size; i++)
        resultCoordinates[i] = coordinates[i] + vector.coordinates[i];

    Vector result(size, resultCoordinates);
    return result;
}

template <typename T>
Vector<T> Vector<T>::operator-(const Vector<T> &vector)throw (DifferentSizes)
{
    if (size != vector.size)
        throw DifferentSizes();

    T *resultCoordinates = new T[size];
    for (int i = 0; i < size; i++)
        resultCoordinates[i] = coordinates[i] - vector.coordinates[i];

    Vector result(size, resultCoordinates);
    return result;
}

template <typename T>
Vector<T> Vector<T>::operator*(const T &scalar)
{
    for (int i = 0; i < size; i++)
        coordinates[i] *= scalar;
    return *this;
}

template <typename T>
Vector<T> Vector<T>::operator=(const Vector<T> &vector)
{
    if (size != vector.size)
    {
        size = vector.size;
        delete[] coordinates;
        coordinates = new T[size];
        for (int i = 0; i < size; i++)
            coordinates[i] = vector.coordinates[i];
    }
    else
        for (int i = 0; i < size; i++)
            coordinates[i] = vector.coordinates[i];
    return *this;
}

template <typename T>
bool Vector<T>::operator==(const Vector<T> &vector)
{
    if (size != vector.size)
        return false;

    for (int i = 0; i < size; i++)
        if (coordinates[i] != vector.coordinates[i])
            return false;
    return true;
}

template <typename T>
bool Vector<T>::isNull()
{
    for (int i = 0; i < size; i++)
        if (coordinates[i] != 0)
            return false;
    return true;
}

template <typename T>
T Vector<T>::at(int position)
{
    return coordinates[position];
}

template <typename T>
int Vector<T>::getSize()
{
    return size;
}
