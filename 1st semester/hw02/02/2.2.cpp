#include <stdio.h>

int power(int x, int k)
{
    int p = 1;
    while (k > 0)
    {
        if ((k % 2) == 1)
            p = p * x;
        x = x * x;
        k = k / 2;
    }
    return p;
}

main()
{
    printf("��������� �������� ����� � ����� �������");
    printf("\n������� �����: ");
    int a = 0;
    scanf("%d", &a);
    printf("������� �������: ");
    int n = 0;
    scanf("%d", &n);

    int res = power(a, n);
    printf("\n���������: %d", res);
}
