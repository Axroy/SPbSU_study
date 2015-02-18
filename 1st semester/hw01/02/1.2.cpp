#include <stdio.h>

int divide(int x, int y);

main()
{
    printf("��������� ������� �������� ������� �� ������� a �� b\n");
    printf("������� a: ");
    int a = 0;
    scanf("%d", &a);
    printf("\n������� b: ");
    int b = 0;
    scanf("%d", &b);

    if (a == 0)
        printf("\n���������: %d", 0);
    if (b == 0)
        printf("\n�� ������ �� ����");

    if ((a > 0 && b > 0) || (a < 0 && b < 0))
    {
        if (a > 0)
            printf("\n���������: %d", divide(a, b));
        else
        {
            a = -a;
            b = -b;
            printf("\n���������: %d", divide(a, b));
        }
    }

    if ((a < 0 && b > 0) || (a > 0 && b < 0))
    {
        if (a < 0)
        {
            a = -a;
            printf("\n���������: %d", -divide(a, b));
        }
        else
        {
            b = -b;
            printf("\n���������: %d", -divide(a, b));
        }
    }

    return 0;
}

int divide(int x, int y)
{
    int k = 0;
    int i = 0;
    while (k <= x)
        {
            i++;
            k = k + y;
        }
    return i - 1;
}
