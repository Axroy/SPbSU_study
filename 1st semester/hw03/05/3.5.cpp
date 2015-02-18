#include <stdio.h>
#include <locale.h>
#include "list.h"

int main()
{
    setlocale(LC_ALL, "rus");
    printf("Программа позволяет осуществлять некоторые действия со списком\n");
    printf("0 - выход\n");
    printf("1 - добавить элемент в сортированный список\n");
    printf("2 - удалить элемент из сортированного списка\n");
    printf("3 - напечатать список\n");

    printf("Введите команду: ");
    int command = 0;
    scanf("%d", &command);
    printf("\n\n");

    List *list = createList();

    int num = 0;
    while (command != 0)
    {
        switch (command)
        {
            case 1:
                printf("Введите число для добавления: ");
                scanf("%d", &num);
                insertSorted(list, num);
                break;
            case 2:
                printf("Введите число, которое хотите удалить: ");
                scanf("%d", &num);
                deleteElement(list, num);
                break;
            case 3:
                printf("\n");
                printList(list);
                printf("\n");
                break;

        }
        printf("\n\n0 - выход\n");
        printf("1 - добавить элемент в сортированный список\n");
        printf("2 - удалить элемент из сортированного списка\n");
        printf("3 - напечатать список\n");
        printf("Введите следующую команду: ");
        scanf("%d", &command);

    }

    deleteList(list);

    return 0;
}
