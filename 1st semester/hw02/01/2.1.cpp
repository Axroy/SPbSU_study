#include <stdio.h>

int fibRecursive(int n)
{
    if ((n == 1) || (n == 2))
        return 1;
    else
        return fibRecursive(n - 1) + fibRecursive(n - 2);
}

int fibIterative(int n)
{
    int a = 1;
    int b = 1;
    if ((n == 1) || (n == 2))
        return 1;
    if (n > 2)
    {
        int x = 0;
        for (int i = 3; i <= n; i++)
        {
            x = a + b;
            a = b;
            b = x;
        }
        return x;
    }
}

main()
{
    printf("��������� �������� ��� ����� ��������� ������ n ����� ���������: ���������� � ����������");
    printf("\n������� n: ");
    int n = 0;
    scanf("%d", &n);

    printf("��������� ������������ �������:\n");
    for (int i = 1; i <= n; i++)
        printf("%d ", fibIterative(i));

    printf("\n��������� ������������ �������:\n");
    for (int i = 1; i <= n; i++)
        printf("%d ", fibRecursive(i));
    return 0;
}
