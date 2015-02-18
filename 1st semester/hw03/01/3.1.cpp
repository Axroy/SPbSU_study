#include <stdio.h>
#include <locale.h>
#include "circularList.h"

int main()
{
    setlocale(LC_ALL, "rus");
    printf("Считалочка. Несколько воинов выстроились в ряд и убивают каждого n-го.\n");
    printf("Программа находит номер позиции воина, который останется последним.\n");
    printf("Введите число воинов: ");
    int amount = 0;
    scanf("%d", &amount);
    printf("Укажите, какого по счету воина убивают: ");
    int period = 0;
    scanf("%d", &period);

    CircularList *list = createList();
    printf("%d", survivor(list, amount, period));
    deleteList(list);
    return 0;
}
