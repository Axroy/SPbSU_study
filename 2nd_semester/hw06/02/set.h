#pragma once

template <typename T>
class Set
{
public:
    Set();
    ~Set();
    void add(const T &value);
    void remove(const T &value);
    bool exists(const T &value);
    Set intersection(Set *set);
    Set association(Set *set);

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
};


template <typename T>
Set<T>::SetElement::SetElement(T newValue, Set::SetElement *nextElement) : value(newValue), next(nextElement)
{
}

template <typename T>
Set<T>::Set() : first(nullptr)
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
    SetElement *newElement = new SetElement(value, first);
    first = newElement;
}

template <typename T>
void Set<T>::remove(const T &value)
{
    if (isEmpty())
        return;

    SetElement *current = first;
    while (current->next != nullptr && current->value != value)
        current = current->next;
    if (current->value == value)
        delete current;
}

template <typename T>
bool Set<T>::exists(const T &value)
{
    if (isEmpty())
        return false;

    SetElement *current = first;
    while (current->next != nullptr && current->value != value)
        current = current->next;
    if (current->value == value)
        return true;
    else
        return false;
}

template <typename T>
Set Set<T>::intersection(Set *set)
{
    Set *result = new Set;
    if (isEmpty() || set->isEmpty())
        return result;

    SetElement *current = first;
    while (current->next != nullptr)
        if (set->exists(current->value))
            result->add(current->value);
    if (set->exists(current->value))
        result->add(current->value);
    return result;
}

template <typename T>
Set Set<T>::association(Set *set)
{
    Set *result = new Set;
    if (!isEmpty())
    {
        SetElement *current = first;
        while (current->next != nullptr)
            result->add(current->value);
        result->add(current->value);
    }
    if (!set->isEmpty())
    {
        SetElement *current = set->first;
        while (current->next != nullptr)
            result->add(current->value);
        result->add(current->value);
    }
    return result;
}

template <typename T>
bool Set<T>::isEmpty()
{
    return first == nullptr;
}

