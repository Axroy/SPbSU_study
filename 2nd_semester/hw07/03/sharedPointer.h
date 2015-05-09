#pragma once

///A template class for smart pointer.
template <typename T>
class SharedPointer
{
public:
    ///Creates new shared pointer on nullptr.
    SharedPointer();
    ///Creates new shared pointer on newObject.
    SharedPointer(T *newObject);
    ///Creates new shared pointer pointing on the same object as one in the parameter.
    SharedPointer(const SharedPointer<T> &pointer);
    ~SharedPointer();
    ///For manual removal of the pointer.
    void remove();
    ///For access to object's fields and functions.
    T *operator-> ();
    ///Redefinition of dereference.
    T &operator* ();
    ///Redefinition of assignment for shared pointers.
    SharedPointer<T> &operator= (const SharedPointer<T> &pointer);
    ///Returns number of links with object.
    int getLinksNumber();

private:
    T *object;
    static int linksNumber;
};

template <typename T>
int SharedPointer<T>::linksNumber = 0;

template <typename T>
SharedPointer<T>::SharedPointer() : object(nullptr)
{
}

template <typename T>
SharedPointer<T>::SharedPointer(T *newObject) : object(newObject)
{
    if (object != nullptr)
        linksNumber++;
}

template <typename T>
SharedPointer<T>::SharedPointer(const SharedPointer<T> &pointer) : object(pointer.object)
{
    if (object != nullptr)
        linksNumber++;
}

template <typename T>
SharedPointer<T>::~SharedPointer()
{
    remove();
}

template <typename T>
void SharedPointer<T>::remove()
{
    if (object == nullptr)
        return;

    linksNumber--;
    if (linksNumber == 0)
        delete object;
}

template <typename T>
T *SharedPointer<T>::operator->()
{
    return object;
}

template <typename T>
T &SharedPointer<T>::operator*()
{
    return *object;
}

template <typename T>
SharedPointer<T> &SharedPointer<T>::operator= (const SharedPointer<T> &pointer)
{
    if (object == pointer.object)
        return *this;

    object = pointer.object;
    if (object != nullptr)
        linksNumber++;
    return *this;
}

template <typename T>
int SharedPointer<T>::getLinksNumber()
{
    return linksNumber;
}
