#include <stdio.h>
#include <locale.h>

main()
{
    setlocale(LC_ALL, "rus");
    printf("��������� ���������, ����� ��, ����������� ������� � ����� ������, �������� ������ ������\n");
    const int size = 255;

    char string1[size];
    char string2[size];

    for (int i = 0; i <= size; i++)
    {
        string1[i] = 0;
        string2[i] = 0;
    }

    printf("\n������� ������ ������: ");
    scanf("%s", &string1);

    printf("\n������� ������ ������: ");
    scanf("%s", &string2);

    const int numberOfSymbols = 255;
    int arrayOfSymbols[numberOfSymbols];
    for (int i = 0; i <= numberOfSymbols; i++)
        arrayOfSymbols[i] = 0;

    for (int i = 0; i <= size - 1; i++)
    {
        arrayOfSymbols[(int)string1[i]]++;
        arrayOfSymbols[(int)string2[i]]--;
    }

    bool isEmpty = true;
    for (int i = 0; i <= numberOfSymbols; i++)
        if(arrayOfSymbols[i] != 0)
            isEmpty = false;

    if (isEmpty)
        printf("\n�����");
    else
        printf("\n������");
    return 0;
}
