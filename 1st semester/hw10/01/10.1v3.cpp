#include <stdio.h>

enum floatNumberState
{
    start,
    sign,
    integerPart,
    dot,
    fracPart,
    eSymbol,
    ePartSign,
    ePartDigits
};

bool isDigit(char symbol)
{
    return symbol >= '0' && symbol <= '9';
}

bool isFloatNumber(char string[])
{
    floatNumberState state = start;
    int i = 0;
    bool error = false;

    while (string[i] != '\0' && !error)
    {
        switch (state)
        {
            case start:
                if (string[i] == '+' || string[i] == '-')
                    state = sign;
                else if (isDigit(string[i]))
                    state = integerPart;
                else
                    error = true;
                i++;
                break;

            case sign:
                if (isDigit(string[i]))
                    state = integerPart;
                else
                    error = true;
                i++;
                break;

            case integerPart:
                if (!isDigit(string[i]))
                {
                    if (string[i] == 'E')
                        state = eSymbol;
                    else if (string[i] == '.')
                        state = dot;
                    else
                        error = true;
                }
                i++;
                break;

            case dot:
                if (isDigit(string[i]))
                    state = fracPart;
                else
                    error = true;
                i++;
                break;

            case fracPart:
                if (!isDigit(string[i]))
                {
                    if (string[i] == 'E')
                        state = eSymbol;
                    else
                        error = true;
                }
                i++;
                break;

            case eSymbol:
                if (string[i] == '+' || string[i] == '-')
                    state = ePartSign;
                else if (isDigit(string[i]))
                    state = ePartDigits;
                else
                    error = true;
                i++;
                break;

            case ePartSign:
                if (isDigit(string[i]))
                    state = ePartDigits;
                else
                    error = true;
                i++;
                break;

            case ePartDigits:
                if (!isDigit(string[i]))
                    error = true;
                i++;
                break;
        }
    }

    if(state != integerPart && state != fracPart && state != ePartDigits)
        error = true;

    return !error;
}

int main()
{
    printf("The program decides whether an expression is a float number or not.\n");
    const int size = 100;
    char string[size] = "";

    printf("Enter the expression: ");
    scanf("%s", &string);

    printf(isFloatNumber(string)? "It is a float number!" : "It is NOT a float number!" );

    return 0;
}

