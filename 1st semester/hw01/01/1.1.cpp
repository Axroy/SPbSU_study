#include <stdio.h>

main()
{
    printf ("��������� ��������� x^4 + x^3 + x^2 + x + 1 ����� � ��� ���������!\n������� x: ");
    int x = 0;
    scanf ("%d", &x);
    
    int sqrX = x * x;
    int result = (sqrX + x) * (sqrX + 1) + 1;
    
    printf ("���������: %d", result);
    return 0;
}
