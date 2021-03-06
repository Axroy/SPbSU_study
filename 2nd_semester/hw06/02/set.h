#pragma once

/// Template class for structure 'set'.
template <typename T>
class Set
{
public:
    Set();
    ~Set();

    ///Adds a value to the set, adds nothing if the value already exsists.
    void add(const T &value);

    ///Removes a value from the set.
    void remove(const T &value);

    ///Returns true if a value is in the set.
    bool exists(const T &value);

    ///Returns a set containing elements which are in both set and set2.
    Set<T> *intersection(Set<T> *set2);

    ///Returns a set containing elements which are either in set or in set2.
    Set<T> *association(Set<T> *set2);

    ///Returns number of elements in the set.
    int getSize();

private:
    class SetElement
    {
    public:
        SetElement(T newValue, SetElement *nextElement);
        T value;
        SetElement *next;
    };

    bool isEmpty();
    SetElement *first;
    int size;
};


template <typename T>
Set<T>::SetElement::SetElement(T newValue, Set::SetElement *nextElement) : value(newValue), next(nextElement)
{
}

template <typename T>
Set<T>::Set() : first(nullptr), size(0)
{
}

template <typename T>
Set<T>::~Set()
{
    if (isEmpty())
        return;

    SetElement *current = first;
    SetElement *previous = first;
    while (current->next != nullptr)
    {
        current = current->next;
        delete previous;
        previous = current;
    }
    delete current;
}

template <typename T>
void Set<T>::add(const T &value)
{
    if (exists(value))
        return;
    SetElement *newElement = new SetElement(value, first);
    first = newElement;
    size++;
}

template <typename T>
void Set<T>::remove(const T &value)
{
    if (isEmpty())
        return;

    SetElement *current = first->next;

    if (current->value == value)
    {
        first->next = current->next;
        delete current;
        size--;
        return;
    }

    while (current->next != nullptr && current->next->value != value)
        current = current->next;

    if (current->next != nullptr)
    {
        SetElement *toBeRemoved = current->next;
        current->next = toBeRemoved->next;
        delete toBeRemoved;
        size--;
    }
}

template <typename T>
bool Set<T>::exists(const T &value)
{
    if (isEmpty())
        return false;

    SetElement *current = first;
    while (current->next != nullptr && current->value != value)
        current = current->next;

    return current->value == value;
}

template <typename T>
Set<T> *Set<T>::intersection(Set<T> *set2)
{
    Set<T> *result = new Set<T>;
    if (isEmpty() || set2->isEmpty())
        return result;

    SetElement *current = first;
    while (current->next != nullptr)
    {
        if (set2->exists(current->value))
            result->add(current->value);
        current = current->next;
    }
    if (set2->exists(current->value))
        result->add(current->value);
    return result;
}

template <typename T>
Set<T> *Set<T>::association(Set<T> *set2)
{
    Set<T> *result = new Set<T>;
    if (!isEmpty())
    {
        SetElement *current = first;
        while (current->next != nullptr)
        {
            result->add(current->value);
            current = current->next;
        }
        result->add(current->value);
    }
    if (!set2->isEmpty())
    {
        SetElement *current = set2->first;
        while (current->next != nullptr)
        {
            if (!result->exists(current->value))
                result->add(current->value);
            current = current->next;
        }
        if (!result->exists(current->value))
            result->add(current->value);
    }
    return result;
}

template <typename T>
int Set<T>::getSize()
{
    return size;
}

template <typename T>
bool Set<T>::isEmpty()
{
    return size == 0;
}

