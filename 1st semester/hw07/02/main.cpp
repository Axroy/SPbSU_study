#include <stdio.h>
#include "line.h"


int main()
{
    //char array[3] = {'a', 'b', 'c'};
    char array2[5] = {'e', 'd', 'c', 'b', 'a'};

    Line *test = createLine();
    Line *test2 = createLine(50);


    Line *test4 = createLine(3, "abc");
    Line *test5 = createLine(5, array2);
    printLine(test4);
    printLine(test5);
    //deleteLine(test);

    concat(test5, test4);
    printLine(test4);
    printf("%d\n\n", lineLength(test4));

    Line *test3 = clone(test4);

    printf("%d\n\n", areEqual(test3, test4));

    printf("%d\n", isEmpty(test));
    printf("%d\n\n", isEmpty(test2));

    int length = lineLength(test);
    printf("%d\n\n", length);

    Line *test6 = copy(test3, 4, 4);
    printLine(test6);

    printf("%d\n\n", lineLength(test6));

    char *testSymbols = getSymbols(test3);
    for (int i = 0; i < 8; i++)
        printf("%c", testSymbols[i]);
    delete[] testSymbols;

    printf("\n\n");
    addLength(test6, 5);
    printLine(test6);


    return 0;
}

