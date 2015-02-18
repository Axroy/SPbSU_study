#include <stdio.h>
#include "parseTree.h"

int main()
{
    printf("Программа вычисляет значение арифметического выражения по его дереву разбора\n");

    const int size = 1000;

    char fileName[size] = "";
    printf("Введите имя файла, содержащего выражение:\n");
    scanf("%s", &fileName);

    FILE *file = fopen(fileName, "r");
    if (file == nullptr)
    {
        printf("Файл не найден!");
        return 0;
    }

    char expression[size] = "";
    fgets(expression, size, file);
    fclose(file);

    ParseTree *tree = createTree();

    insertExpression(tree, expression);
    printPreOrder(tree);

    int result = solveTree(tree);
    printf("\n%d", result);

    removeTree(tree);
    return 0;
}

