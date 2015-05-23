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
    ///Deletes object when there are no pointers on it.
    ~SharedPointer();
    ///For manual removal of the pointer.
    void remove();
    ///For access to object's fields and functions.
    T *operator ->();
    ///Redefinition of dereference.
    T &operator *();
    ///Redefinition of assignment for shared pointers.
    SharedPointer<T> &operator =(const SharedPointer<T> &pointer);
    ///Returns number of links with object.
    int getLinksNumber();

private:
    struct PointerData
    {
        PointerData(T *object, int linksNumber) : object(object), linksNumber(linksNumber)
        {

        }
        ~PointerData()
        {
            delete object;
        }

        T *object;
        int linksNumber;
    };

    PointerData *pointerData;
};



template <typename T>
SharedPointer<T>::SharedPointer() : pointerData(new PointerData(nullptr, 0))
{

}

template <typename T>
SharedPointer<T>::SharedPointer(T *newObject) : pointerData(new PointerData(newObject, 1))
{
    if (newObject == nullptr)
        pointerData->linksNumber = 0;
}

template <typename T>
SharedPointer<T>::SharedPointer(const SharedPointer<T> &pointer) : pointerData(pointer.pointerData)
{
    if (pointerData->object == nullptr)
        pointerData->linksNumber = 0;
    else
        pointerData->linksNumber++;
}

template <typename T>
SharedPointer<T>::~SharedPointer()
{
    remove();
}

template <typename T>
void SharedPointer<T>::remove()
{
    if (pointerData->object == nullptr)
        return;

    pointerData->linksNumber--;
    if (pointerData->linksNumber == 0)
        delete pointerData->object;
}

template <typename T>
T *SharedPointer<T>::operator ->()
{
    return pointerData->object;
}

template <typename T>
T &SharedPointer<T>::operator *()
{
    return *pointerData->object;
}

template <typename T>
SharedPointer<T> &SharedPointer<T>::operator =(const SharedPointer<T> &pointer)
{
    if (pointerData->object == pointer.pointerData->object)
        return *this;

    this->remove();
    pointerData->object = pointer.pointerData->object;
    if (pointerData->object != nullptr)
        pointerData->linksNumber++;
    return *this;
}

template <typename T>
int SharedPointer<T>::getLinksNumber()
{
    return pointerData->linksNumber;
}
