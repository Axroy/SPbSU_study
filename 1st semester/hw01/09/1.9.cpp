#include <stdio.h>

main()
{
      printf("��������� �������� ����� a � ����� ������� n\n");
      printf("������� a: ");
      int a = 0;
      scanf("%d", &a);
      printf("\n������� n: ");
      int n = 0;
      scanf("%d", &n);
      int i = 0;
      int res = a;
      for (i = 2; i <= n; i++)
          res = res * a;
      printf("\n���������: %d", res);
      return 0;
}
