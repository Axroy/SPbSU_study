#include <stdio.h>

const int primeNumber = 58;
const int modulus = 67;

int hashFunction(char string[], int length)
{
    int result = 0;
    for (int i = 0; i < length; i++)
        result = (result * primeNumber + string[i]) % modulus;

    return result;
}

int newHash(int oldHash, int oldHashStartingPos, int oldHashEndingPos, char string[], int maxExponent)
{
    int result = oldHash - string[oldHashStartingPos] * maxExponent % modulus;
    while (result < 0)
        result += modulus;
    result = (result * primeNumber) % modulus;
    result = (result + string[oldHashEndingPos + 1]) % modulus;

    return result;
}

void substringSearch(char string[], char substring[], int substringHash, int substringLength)
{
    int position = 0;
    bool success = false;
    bool atLeastOneSuccess = false;

    int maxExponent = 1;
    for (int i = 0; i < substringLength - 1; i++)
        maxExponent = maxExponent * primeNumber % modulus;
    maxExponent = maxExponent % modulus;

    int hash = hashFunction(string, substringLength);

    while (string[position] != '\0')
    {
        if (substringHash == hash)
        {
            success = true;
            for (int i = 0; i < substringLength; i++)
                if (substring[i] != string[position + i])
                {
                    success = false;
                    break;
                }
        }
        hash = newHash(hash, position, substringLength + position - 1, string, maxExponent);
        position++;

        if (success)
        {
            printf("Substring starting position: %d\n", position - 1);
            success = false;
            atLeastOneSuccess = true;
        }
    }
    if (!atLeastOneSuccess)
        printf("Substring not found!");
}


int main()
{
    printf("The program uses Rabin-Karp algorythm to find substing in a string.\n");
    const int size = 1000;

    printf("Enter the string:\n");
    char string[size] = "";
    scanf("%s", &string);

    printf("Enter the substring:\n");
    char substring[size] = "";
    scanf("%s", &substring);

    int substringLength = 0;
    while (substring[substringLength] != '\0')
        substringLength++;

    substringSearch(string, substring, hashFunction(substring, substringLength), substringLength);

    return 0;
}

