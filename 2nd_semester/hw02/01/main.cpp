#include <iostream>
#include "list.h"
#include "singleLinkedList.h"
#include "doubleLinkedList.h"
#include "singleLinkedListTests.h"
#include "doubleLinkedListTests.h"


int main()
{
    SingleLinkedListTests SLLTests;
    QTest::qExec(&SLLTests);

    DoubleLinkedListTests DLLTests;
    QTest::qExec(&DLLTests);

    return 0;
}

