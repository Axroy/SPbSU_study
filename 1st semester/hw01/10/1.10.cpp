#include <stdio.h>

main()
{
    printf("��������� ���������, �������� �� ������ (������ 10 ��������) �����������\n");
    const int size = 10;
    char string[size];
    printf("������� ������:\n");
    scanf("%s", &string);

    bool isPalindrome = true;
    for (int i = 0; i <= size/2; i++)
        if (string[i] != string[size - (i + 1)])
            isPalindrome = false;

    if (isPalindrome)
        printf("��������");
    else
        printf("�� ��������");
    return 0;
}
