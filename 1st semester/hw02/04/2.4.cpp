#include <stdio.h>

int gcd(int a, int b)
{
        if (a == 0)
            return b;
        return gcd(b % a, a);
}

bool compare(int numA, int denA, int numB, int denB)
{
    numA = numA * denB;
    numB = numB * denA;
    return (numA >= numB);
}

void swap(int arrayNum[], int arrayDen[], int a, int b)
{
    int tempNum = arrayNum[a];
    int tempDen = arrayDen[a];
    arrayNum[a] = arrayNum[b];
    arrayDen[a] = arrayDen[b];
    arrayNum[b] = tempNum;
    arrayDen[b] = tempDen;
}

void sort(int arrayNum[], int arrayDen[], int sizeA)
{
    for (int i = 0; i < sizeA; i++)
        for (int j = i + 1; j < sizeA; j++)
            if(compare(arrayNum[i], arrayDen[i], arrayNum[j], arrayDen[j]))
                swap(arrayNum, arrayDen, i, j);
}
main()
{
    const int size = 100;
    printf("Программа печатает все простые несократимые дроби между 0 и 1, знаменатели которых не превышают n\n");
    printf("Введите n: ");
    int n = 0;
    scanf("%d", &n);
    int arrayNumerator[size];
    int arrayDenominator[size];

    int counter = -1;
    for (int i = 2; i <= n; i++)
        for (int j = 1; j <= i - 1; j++)
            if (gcd(i, j) == 1)
            {
                counter++;
                arrayNumerator[counter] = j;
                arrayDenominator[counter] = i;
            }
    sort(arrayNumerator, arrayDenominator, counter);

    for (int i = 0; i <= counter; i++)
        printf("%d ", arrayNumerator[i]);
    printf("\n");
    for (int i = 0; i <= counter; i++)
        printf("- ");
    printf("\n");
    for (int i = 0; i <= counter; i++)
        printf("%d ", arrayDenominator[i]);
    return 0;
}
