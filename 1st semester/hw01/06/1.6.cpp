#include <stdio.h>

main()
{
    printf("��������� ������� ���������� ��������� ��������� (����� 2) � ������ (����� 10)\n");
    const int sizeStr = 10;
    const int sizeSubStr = 2;
    printf("\n������� ������:\n");
    char string[sizeStr];
    scanf("%s", &string);
    printf("\n������� ���������:\n");
    char substring[sizeSubStr];
    scanf ("%s", &substring);

    int k = 0;
    bool isIn = true;
    for (int i = 0; i < sizeStr; i++)
        if (string[i] == substring[0])
        {
            isIn = true;
            for (int j = 1; j < sizeSubStr; j++)
                if (string[j + i] != substring[j])
                    isIn = false;
            if (isIn)
                k++;
        }

    printf("\n���������� ���������: %d", k);
    return 0;
}
