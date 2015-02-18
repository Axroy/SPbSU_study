#include <stdio.h>

main()
{
      printf("Программа выводит все простые числа, не превосходящие заданного числа n\n");
      printf("Введите n: ");
      int n = 0;
      scanf("%d", &n);
      int array[n];
      int i = 0;
      for (i = 1; i <= n; i++)
          array[i] = i;

      int j = 0;
      for (i = 2; i <= n; i++)
          if (array[i] != 0)
          {
              j = i * 2;
              while (j <= n)
              {
                  array[j] = 0;
                  j = j + i;
              }
          }


      for (i = 1; i <= n; i++)
          if (array[i] != 0)
              printf("%d ", array[i]);
      return 0;
}


