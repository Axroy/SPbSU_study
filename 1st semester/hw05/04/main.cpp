#include <stdio.h>
#include "directory.h"

enum command
{
    exit,
    enter,
    findName,
    findPhone,
    save
};

int main()
{
    printf("Программа - телефонный справочник.\n");
    const int nameSize = 20;
    const int fileNameSize = 1000;
    char name[nameSize] = "some person";
    int number = 1234567;

    char fileName[fileNameSize];
    Directory *directory = createDirectory();
    bool hasStartingFile = false;
    printf("Есть ли файл с данными? (1 - да, 0 - нет) ");
    scanf("%d", &hasStartingFile);

    if (hasStartingFile)
    {
        printf("Введите имя файла с данными: ");
        scanf("%s", &fileName);
        readFromFile(directory, fileName);
    }

    command cmd;

    printf("\n0 - выйти");
    printf("\n1 - добавить запись");
    printf("\n2 - найти имя по телефону");
    printf("\n3 - найти телефон по имени");
    printf("\n4 - сохранить текущие данные в файл");

    while (cmd != exit)
    {
        printf("\nВведите команду: ");
        scanf("%d", &cmd);
        switch (cmd)
        {
            case enter:
                printf("Введите имя и телефон: ");
                scanf("%s %d", &name, &number);
                insertSorted(directory, name, number);
                break;

            case findName:
                printf("Введите телефон: ");
                scanf("%d", &number);
                findNameByPhone(directory, number);
                break;

            case findPhone:
                printf("Введите имя: ");
                scanf("%s", &name);
                findPhoneByName(directory, name);
                break;

            case save:
                printf("В какой файл сохранить? ");
                scanf("%s", &fileName);
                saveToFile(directory, fileName);
                break;

            default:
                break;
        }
    }

    deleteDirectory(directory);

    return 0;
}

