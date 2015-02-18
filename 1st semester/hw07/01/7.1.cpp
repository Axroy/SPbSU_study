#include <stdio.h>

int findRealVariant(int variants[], int studentNumber)
{
    if (variants[studentNumber] == 0 || variants[studentNumber] == 1 || variants[studentNumber] == 2)
        return variants[studentNumber];

    return findRealVariant(variants, variants[studentNumber]);
}

int main()
{
    printf("The program solves the problem about students.\n");

    printf("Enter the amount of students: ");
    int amountOfStudents = 0;
    scanf("%d", &amountOfStudents);

    printf("For each student enter his number and his variant:\n");
    int *variants = new int[amountOfStudents];
    int studentNumber = 0;
    for (int i = 0; i < amountOfStudents; i++)
    {
        scanf("%d", &studentNumber);
        studentNumber--;
        scanf("%d", &variants[studentNumber]);
        variants[studentNumber]--;
    }

    for (int i = 0; i < amountOfStudents; i++)
        variants[i] = findRealVariant(variants, i);

    printf("\nResult (student -- variant):\n");
    for (int i = 0; i < amountOfStudents; i++)
        printf("%d -- %d\n", i + 1, variants[i] + 1);

    delete[] variants;

    return 0;
}

