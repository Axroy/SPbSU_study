#include "list.h"

List::List()
{
    //head = new ListElement(0, nullptr);
}

List::~List()
{

}


List::ListElement::ListElement(int value, List::ListElement *neext)
{
    data = value;
    next = neext;
}
