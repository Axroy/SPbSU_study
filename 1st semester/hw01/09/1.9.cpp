#include <stdio.h>

main()
{
      printf("Программа возводит число a в целую степень n\n");
      printf("Введите a: ");
      int a = 0;
      scanf("%d", &a);
      printf("\nВведите n: ");
      int n = 0;
      scanf("%d", &n);
      int i = 0;
      int res = a;
      for (i = 2; i <= n; i++)
          res = res * a;
      printf("\nРезультат: %d", res);
      return 0;
}
