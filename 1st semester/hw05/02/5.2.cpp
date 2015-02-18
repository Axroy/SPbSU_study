#include <stdio.h>
#include <math.h>

void invert(unsigned char *array, int size)
{
     int i = 0;
     int temp = 0;
     for (i = 0; i < size/2; i++)
     {
         temp = array[i];
         array[i] = array[size - i - 1];
         array[size - i - 1] = temp;
     }
}

long long int convertToDecimal(bool *array, int size)
{
    long long int result = 0;
    for (int i = size - 1; i >= 0; i--)
        result += array[i] * pow(2, size - i - 1);

    return result;
}

int main()
{
    printf("The program prints double value in form: mantissa * 2^exponent.\n");

    const int mantissaSize = 52;
    const int exponentSize = 11;
    const int byteSize = 8;

    printf("Enter the value: ");
    double number = 0;
    scanf("%lf", &number);

    if (number == 0)
    {
        printf("+0,0 * 2^0");
        return 0;
    }

    unsigned char mask = 128;
    unsigned char *bytes = (unsigned char*)&number;

    invert(bytes, byteSize);

    printf((bytes[0] & mask)? "-" : "+");

    bool exponent[exponentSize];
    bytes[0] = bytes[0] << 1;
    for (int i = 0; i < byteSize - 1; i++)
    {
        exponent[i] = bytes[0] & mask;
        bytes[0] = bytes[0] << 1;
    }
    for (int i = 0; i < byteSize - 4; i++)
    {
        exponent[i + byteSize - 1] = bytes[1] & mask;
        bytes[1] = bytes[1] << 1;
    }



    bool mantissa[mantissaSize];
    for (int i = 0; i < 4; i++)
    {
        mantissa[i] = bytes[1] & mask;
        bytes[1] = bytes[1] << 1;
    }
    for (int i = 2; i < byteSize; i++)
        for (int j = 0; j < byteSize; j++)
        {
            mantissa[j + (byteSize - 4) + byteSize * (i - 2)] = bytes[i] & mask;
            bytes[i] = bytes[i] << 1;
        }

    printf("%lf * 2^(%d)", (double)convertToDecimal(mantissa, mantissaSize) / (double)pow(2, mantissaSize) + 1,
           convertToDecimal(exponent, exponentSize) - 1023);

    return 0;
}

