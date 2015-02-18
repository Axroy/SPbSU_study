#include <stdio.h>
#include <locale.h>

void printWords(FILE *file)
{
    const int size = 1000;
    const int numberOfSymbols = 58;

    bool arrayOfSymbols[numberOfSymbols];
    for (int j = 0; j < numberOfSymbols; j++)
        arrayOfSymbols[j] = 0;

    char word[size] = "";
    char symbol = '0';

    int wordPos = 0;
    while (!feof(file))
    {
        symbol = getc(file);
        if (symbol != ' ')
        {
            if ((symbol < 'A') || (symbol > 'z') || (symbol > 'Z' && symbol < 'a'))
            {
                        word[wordPos] = symbol;
                        wordPos++;
            }
            else
            {
                if (symbol < 'a')
                {
                    if (!arrayOfSymbols[symbol - 'A'] && !arrayOfSymbols[symbol - ('a' - 'A')])
                    {
                        word[wordPos] = symbol;
                        wordPos++;
                        arrayOfSymbols[symbol - 'A'] = true;
                        arrayOfSymbols[symbol - ('a' - 'A')] = true;
                    }
                }
                else
                    if (!arrayOfSymbols[symbol - 'A'] && !arrayOfSymbols[symbol - 'a'])
                    {
                        word[wordPos] = symbol;
                        wordPos++;
                        arrayOfSymbols[symbol - 'A'] = true;
                        arrayOfSymbols[symbol - 'a'] = true;
                    }
            }
        }
        else
        {
            for (int j = 0; j < numberOfSymbols; j++)
                arrayOfSymbols[j] = false;
            for (int j = 0; j <= wordPos; j++)
                printf("%c", word[j]);
            printf(" ");
            for (int j = 0; j <= wordPos; j++)
                word[j] = ' ';
            wordPos = 0;
        }
    }

    if (word[0] != ' ')
    {
        for (int j = 0; j < wordPos - 1; j++)
            printf("%c", word[j]);
    }
}

int main()
{
    setlocale(LC_ALL, "rus");
    printf("Программа выводит все слова из файла с текстом, предварительно оставив в каждом слове только первые вхождения каждой буквы.");

    const int size = 1000;

    char fileName[size] = "";
    printf("\nВведите имя файла: ");
    scanf("%s", fileName);

    FILE *file = fopen(fileName, "r");
    if (file == nullptr)
    {
        printf("Файл не найден!");
        return 0;
    }

    printWords(file);

    fclose(file);
    return 0;
}
