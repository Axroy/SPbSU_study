#include <stdio.h>

void invert(int arr[], int k);

main()
{
      printf("Программа меняет два участка n и m массива местами\n");
      printf("Введите длину участка n: ");
      int n = 0;
      scanf("%d", &n);
      printf("\nВведите длину участка m: ");
      int m = 0;
      scanf("%d", &m);
      int array[n + m];
      printf("\nВведите элементы всего массива: ");
      int i = 0;
      for (i = 0; i < n + m; i++)
          scanf("%d", &array[i]);

      invert(array, n);
      invert(array + n, m);
      invert(array, n + m);

      for (i = 0; i < n + m; i++)
          printf("%d ", array[i]);
      return 0;
}

void invert(int arr[], int k)
{
     int i = 0;
     int temp = 0;
     for (i = 0; i < k/2; i++)
     {
         temp = arr[i];
         arr[i] = arr[k - i - 1];
         arr[k - i - 1] = temp;
     }
}
