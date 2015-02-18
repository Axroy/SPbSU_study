#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

bool isDifferent(int array[], int sizeA)
{
    bool elementsDiffer = true;
    for (int i = 0; i < sizeA; i++)
        for (int j = i + 1; j < sizeA; j++)
            if (array[i] == array[j])
                elementsDiffer = false;
    return elementsDiffer;
}

main()
{
    setlocale(LC_ALL, "rus");
    printf("Игра 'Быки и коровы'\n");
    const int size = 4;
    int arrayNum[size];
    srand(time(0));

    for (int i = 0; i < size; i++)
        arrayNum[i] = 0;
    while (!isDifferent(arrayNum, size))
        for (int i = 0; i < size; i++)
            arrayNum[i] = rand() % 10;

    for (int i = 0; i < size; i++)
        printf("%d", arrayNum[i]);

    bool hasWon = false;
    int guessedArray[size];
    while (!hasWon)
    {
        int bulls = 0;
        int cows = 0;
        printf("\n\nПопытайтесь отгадать число: ");
        int num = 0;
        scanf("%d", &num);
        for (int i = size - 1; i >= 0; i--)
        {
            guessedArray[i] = num % 10;
            num = num / 10;
        }


        for (int i = 0; i < size; i++)
            if (guessedArray[i] == arrayNum[i])
                bulls++;

        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                if ((guessedArray[i] == arrayNum[j]) && (i != j))
                    cows++;

        if (bulls == size)
            hasWon = true;
        else
        {
            printf("\nЧисло быков: %d", bulls);
            printf("\nЧисло коров: %d", cows);
        }
    }
    printf("\nВы отгадали число!");
    return 0;
}
