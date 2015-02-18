#include <stdio.h>
#include <locale.h>

void printComments(FILE *file)
{
    const int size = 1000;
    char line[size] = "";
    char commentLine[size] = "";
    bool isInLineComment = false;
    bool isInBlockComment = false;
    bool isInTextString = false;
    int linePos = 0;
    int commentLinePos = 2;

    while (!feof(file))
    {
        fgets(line, size, file);
        while (line[linePos] != '\n')
        {
            if (isInLineComment)
            {
                commentLine[commentLinePos] = line[linePos];
                commentLinePos++;
            }
            else
            {
                if (!isInBlockComment && !isInTextString)
                {
                    if (line[linePos] == '/')
                    {
                        linePos++;
                        if (line[linePos] == '/')
                        {
                            isInLineComment = true;
                            commentLine[0] = '/';
                            commentLine[1] = '/';
                        }
                        if (line[linePos] == '*')
                            isInBlockComment = true;
                    }
                    if (line[linePos] == '"')
                        isInTextString = true;
                }
                else
                {
                    if (isInBlockComment)
                    {
                        if (line[linePos] == '*')
                        {
                            linePos++;
                            if (line[linePos] == '/')
                                isInBlockComment = false;
                        }
                    }

                    if (isInTextString)
                    {
                        if (line[linePos] == '"')
                            isInTextString = false;
                    }
                }

            }
            linePos++;
        }
        isInTextString = false;
        isInLineComment = false;
        if (commentLine[0] != ' ' && !feof(file))
            printf("\n%s", commentLine);
        for (int i = 0; i < commentLinePos; i++)
            commentLine[i] = ' ';
        commentLinePos = 2;
        linePos = 0;
    }
}

int main()
{
    setlocale(LC_ALL, "rus");
    printf("Программа показывает все однострочные комментарии C++ в файле.");

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

    printComments(file);

    fclose(file);

    return 0;
}
