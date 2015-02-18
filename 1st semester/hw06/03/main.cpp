#include <stdio.h>
#include "AVLTree.h"

enum command
{
    exit,
    addNode,
    deleteNode,
    checkExsistence,
    printPreOrder,
    printPostOrder,
    printExplicitForm,
};

void printCommands()
{
    printf("0 - выход\n");
    printf("1 - добавить значение в множество\n");
    printf("2 - удалить значение из множества\n");
    printf("3 - проверить, принадлежит ли значение множеству\n");
    printf("4 - напечатать текущие элементы множества в возрастающем порядке\n");
    printf("5 - напечатать текущие элементы множества в убывающем порядке\n");
    printf("6 - напечатать текущие элементы множества в формате (<значение> <левое поддерево> <правое поддерево>)\n");
    printf("\n");
}

int main()
{
    printf("Программа реализует АТД ""множество"" на основе АВЛ-дерева\n\n");
    AVLTree *tree = createTree();

    printCommands();
    printf("Введите команду: ");

    command cmd;
    scanf("%d", &cmd);

    int value = 0;
    while (cmd != exit)
    {
        switch (cmd)
        {
            case addNode:
                printf("Введите добавляемое значение: ");
                scanf("%d", &value);
                insertNode(tree, value);
                break;

            case deleteNode:
                printf("Введите удаляемое значение: ");
                scanf("%d", &value);
                removeNode(tree, value);
                break;

            case checkExsistence:
                printf("Введите значение, наличие которого хотите проверить: ");
                scanf("%d", &value);
                printf("%s", isInTree(tree, value)? "Есть" : "Нет");
                break;

            case printPreOrder:
                printf("\n");
                printAscending(tree);
                break;

            case printPostOrder:
                printf("\n");
                printDescending(tree);
                break;

            case printExplicitForm:
                printf("\n");
                printDebug(tree);
                break;
        }
        printf("\n\n");
        printCommands();
        printf("Введите команду: ");
        scanf("%d", &cmd);
    }

    removeTree(tree);

    return 0;
}
