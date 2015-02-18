#include <stdio.h>

main()
{
    printf ("Программа вычисляет x^4 + x^3 + x^2 + x + 1 всего в два умножения!\nВведите x: ");
    int x = 0;
    scanf ("%d", &x);
    
    int sqrX = x * x;
    int result = (sqrX + x) * (sqrX + 1) + 1;
    
    printf ("Результат: %d", result);
    return 0;
}
