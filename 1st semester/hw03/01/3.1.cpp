#include <stdio.h>
#include <locale.h>
#include "circularList.h"

int main()
{
    setlocale(LC_ALL, "rus");
    printf("����������. ��������� ������ ����������� � ��� � ������� ������� n-��.\n");
    printf("��������� ������� ����� ������� �����, ������� ��������� ���������.\n");
    printf("������� ����� ������: ");
    int amount = 0;
    scanf("%d", &amount);
    printf("�������, ������ �� ����� ����� �������: ");
    int period = 0;
    scanf("%d", &period);

    CircularList *list = createList();
    printf("%d", survivor(list, amount, period));
    deleteList(list);
    return 0;
}
