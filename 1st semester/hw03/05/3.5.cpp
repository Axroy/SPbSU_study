#include <stdio.h>
#include <locale.h>
#include "list.h"

int main()
{
    setlocale(LC_ALL, "rus");
    printf("��������� ��������� ������������ ��������� �������� �� �������\n");
    printf("0 - �����\n");
    printf("1 - �������� ������� � ������������� ������\n");
    printf("2 - ������� ������� �� �������������� ������\n");
    printf("3 - ���������� ������\n");

    printf("������� �������: ");
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
                printf("������� ����� ��� ����������: ");
                scanf("%d", &num);
                insertSorted(list, num);
                break;
            case 2:
                printf("������� �����, ������� ������ �������: ");
                scanf("%d", &num);
                deleteElement(list, num);
                break;
            case 3:
                printf("\n");
                printList(list);
                printf("\n");
                break;

        }
        printf("\n\n0 - �����\n");
        printf("1 - �������� ������� � ������������� ������\n");
        printf("2 - ������� ������� �� �������������� ������\n");
        printf("3 - ���������� ������\n");
        printf("������� ��������� �������: ");
        scanf("%d", &command);

    }

    deleteList(list);

    return 0;
}
