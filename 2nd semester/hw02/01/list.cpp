#include "list.h"

List::List()
{
    //head = new ListElement(0, nullptr);
}

List::~List()
{

}


List::ListElement::ListElement(int value, List::ListElement *next)
{
    data = value;
    next = next;
}
