#pragma once

template <typename T>
class SharedPointer
{
public:
    SharedPointer();
    SharedPointer(T *newObject);
    SharedPointer(const SharedPointer<T> &pointer);
    ~SharedPointer();
    void remove();
    T *operator-> ();
    T &operator* ();
    SharedPointer<T> &operator= (const SharedPointer<T> &pointer);

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
