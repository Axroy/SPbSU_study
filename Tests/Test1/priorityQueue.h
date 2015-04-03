#pragma once

template <typename T>
class PriorityQueue
{
public:
    PriorityQueue();
    void enqueue(T value, int priority);
    T dequeue();
    T getFirstValue();


private:
    class QueueElement
    {
    public:
        QueueElement(T newValue, int newPriority, QueueElement *nextElement);

        T value;
        int priority;
        QueueElement *next;
    };

    QueueElement *first;

    bool isEmpty();
};


template <typename T>
PriorityQueue<T>::QueueElement::QueueElement(T newValue, int newPriority, PriorityQueue::QueueElement *nextElement)
{
    value = newValue;
    priority = newPriority;
    next = nextElement;
}

template <typename T>
PriorityQueue<T>::PriorityQueue()
{
    first = nullptr;
}

template <typename T>
void PriorityQueue<T>::enqueue(T value, int priority)
{
    if(isEmpty())
    {
        first = new QueueElement(value, priority, nullptr);
        return;
    }

    if (priority > first->priority)
    {
        QueueElement *afterEnqueued = first;
        first = new QueueElement(value, priority, afterEnqueued);
    }

    QueueElement *current = first;
    while (current->next != nullptr && current->next->priority > priority)
        current = current->next;
    if (current->next == nullptr)
        current->next = new QueueElement(value, priority, nullptr);
    else
    {
        QueueElement *afterEnqueued = current->next->next;
        current->next = new QueueElement(value, priority, afterEnqueued);
    }
}

template <typename T>
T PriorityQueue<T>::getFirstValue()
{
    return first->value;
}

template <typename T>
bool PriorityQueue<T>::isEmpty()
{
    return first == nullptr;
}
