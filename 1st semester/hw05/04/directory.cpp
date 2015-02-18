#include <stdio.h>
#include <stdlib.h>
#include "directory.h"

const int nameSize = 20;
const int size = 1000;

struct DirectoryElement
{
    char name[nameSize];
    int phoneNumber;
    DirectoryElement *next;
};

struct Directory
{
    DirectoryElement *head;
};



DirectoryElement *createElement(char name[], int number, DirectoryElement *next)
{
    DirectoryElement *element = new DirectoryElement;
    element->next = next;
    element->phoneNumber = number;
    for (int i = 0; i < nameSize; i++)
        element->name[i] = name[i];
    return element;
}

Directory *createDirectory()
{
    Directory *directory = new Directory;
    DirectoryElement *element = createElement("guard", 0, nullptr);
    directory->head = element;

    return directory;
}

bool isEmpty(Directory *directory)
{
    return directory->head->next == nullptr;
}

bool endOfDirectory(DirectoryElement *element)
{
    return element->next == nullptr;
}

void deleteDirectory(Directory *directory)
{
    if (!isEmpty(directory))
    {
        DirectoryElement *element = directory->head->next;
        DirectoryElement *current = element;
        while (!endOfDirectory(element))
        {
            current = element;
            delete current;
            element = element->next;
        }
    }
    delete directory->head;
    delete directory;
}

void insertFirst(Directory *directory, char name[], int number)
{
    DirectoryElement *element = createElement(name, number, directory->head->next);
    directory->head->next = element;
}

void insertAfter(DirectoryElement *element, char name[], int number)
{
    DirectoryElement *newElement = createElement(name, number, element->next);
    element->next = newElement;
}

int compareStrings(char string1[], char string2[])
{
    int i = 0;
    while (string1[i] != '\0' || string2[i] != '\0')
    {
        if (string1[i] > string2[i])
            return 1;
        if (string1[i] < string2[i])
            return -1;
        i++;
    }
    if (string1[i] != '\0')
        return -1;
    if (string2[i] != '\0')
        return 1;
    if (string1[i] == '\0' && string2[i] == '\0')
        return 0;
}

void insertSorted(Directory *directory, char name[], int number)
{
    DirectoryElement *current = directory->head->next;
    if (isEmpty(directory) || compareStrings(current->name, name) == 1 || compareStrings(current->name, name) == 0)
        insertFirst(directory, name, number);
    else
    {
        while (!endOfDirectory(current) && compareStrings(current->next->name, name) == -1)
        {
            current = current->next;
        }
        insertAfter(current, name, number);
    }
}

void printDirectory(Directory *directory)
{
        if (!isEmpty(directory))
        {
            DirectoryElement *element = directory->head->next;
            while (!endOfDirectory(element))
            {
                printf("%s %d\n", element->name, element->phoneNumber);
                element = element->next;
            }
            printf("%s %d", element->name, element->phoneNumber);
        }
}

void findNameByPhone(Directory *directory, int number)
{
    DirectoryElement *current = directory->head->next;
    while (current->phoneNumber != number && !endOfDirectory(current))
        current = current->next;
    if (current->phoneNumber == number)
        printf("%s", current->name);
    else
        printf("Имя не найдено!");
}

void findPhoneByName(Directory *directory, char name[])
{
    DirectoryElement *current = directory->head->next;
    while (compareStrings(current->name, name) != 0 && !endOfDirectory(current))
        current = current->next;
    if (compareStrings(current->name, name) == 0)
        printf("%d", current->phoneNumber);
    else
        printf("Телефон не найден!");
}

void saveToFile(Directory *directory, char fileName[])
{
    if (!isEmpty(directory))
    {
        FILE *file = fopen(fileName, "w");
        DirectoryElement *current = directory->head->next;
        while (!endOfDirectory(current))
        {
            fprintf(file, "%s %d\n", current->name, current->phoneNumber);
            current = current->next;
        }
        fprintf(file, "%s %d\n", current->name, current->phoneNumber);
        fclose(file);
    }
    else
        printf("В справочнике нет ни одной записи!");
}

void readFromFile(Directory *directory, char fileName[])
{
    FILE *file = fopen(fileName, "r");

    if (file == nullptr)
    {
        printf("Файл не найден!");
        return;
    }
    char string[size] = "";
    char name[nameSize] = "";
    char number[7] = "";
    int namePos = 0;
    int numberPos = 0;
    int stringPos = 0;

    while (!feof(file))
    {
        fgets(string, size, file);
        while (string[stringPos] != ' ')
        {
            name[namePos] = string[stringPos];
            stringPos++;
            namePos++;
        }
        namePos = 0;
        stringPos++;

        while (string[stringPos] != '\n')
        {
            number[numberPos] = string[stringPos];
            stringPos++;
            numberPos++;
        }
        numberPos = 0;
        stringPos = 0;

        if (string[0] != ' ')
            insertSorted(directory, name, atoi(number));

        for (int i = 0; i <= 7; i++)
            number[i] = ' ';

        while (name[namePos] != '\0')
        {
            name[namePos] = ' ';
            namePos++;
        }
        namePos = 0;

        while (string[stringPos] != '\n')
        {
            string[stringPos] = ' ';
            stringPos++;
        }
        stringPos = 0;
    }

    fclose(file);
}
