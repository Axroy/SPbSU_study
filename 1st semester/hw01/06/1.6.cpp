#include <stdio.h>

main()
{
    printf("Программа находит количество вхождений подстроки (длины 2) в строку (длины 10)\n");
    const int sizeStr = 10;
    const int sizeSubStr = 2;
    printf("\nВведите строку:\n");
    char string[sizeStr];
    scanf("%s", &string);
    printf("\nВведите подстроку:\n");
    char substring[sizeSubStr];
    scanf ("%s", &substring);

    int k = 0;
    bool isIn = true;
    for (int i = 0; i < sizeStr; i++)
        if (string[i] == substring[0])
        {
            isIn = true;
            for (int j = 1; j < sizeSubStr; j++)
                if (string[j + i] != substring[j])
                    isIn = false;
            if (isIn)
                k++;
        }

    printf("\nКоличество вхождений: %d", k);
    return 0;
}
