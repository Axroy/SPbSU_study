#include <stdio.h>

void invert(int arr[], int k);

main()
{
      printf("��������� ������ ��� ������� n � m ������� �������\n");
      printf("������� ����� ������� n: ");
      int n = 0;
      scanf("%d", &n);
      printf("\n������� ����� ������� m: ");
      int m = 0;
      scanf("%d", &m);
      int array[n + m];
      printf("\n������� �������� ����� �������: ");
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
