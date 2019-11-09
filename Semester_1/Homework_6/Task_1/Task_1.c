#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define sizeOfDouble 8 * 8
typedef union Number Number;

union Number
{
    double value;
    char binaryForm[8];
};

int* createArray(int size)
{
    int* array = malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++)
    {
        array[i] = 0;
    }

    return array;
}

int* getBinaryForm(char* number)
{
    int* binaryForm = createArray(sizeOfDouble);
    for (int i = 0; i < 8; i ++)
    {
        for (int j = 0; j < 8; j++)
        {
            binaryForm[i * 8 + j] = number[i] >> j & 1;
        }
    }

    return binaryForm;
}

int* getMantissaBinaryForm(int* binaryForm)
{
    int* mantissaBinaryForm = createArray(52);
    for (int i = 0; i < 52; i++)
    {
        mantissaBinaryForm[i] = binaryForm[i];
    }
    return mantissaBinaryForm;
}

int* getExponentBinaryForm(int* binaryForm)
{
    int* exponentBinaryForm = createArray(11);
    for (int i = 52; i < sizeOfDouble - 1; i++)
    {
        exponentBinaryForm[i - 52] = binaryForm[i];
    }
    return exponentBinaryForm;
}

bool isPositive(int* binaryForm)
{
    return binaryForm[sizeOfDouble - 1];
}

void printBinaryForm(int* binaryForm, int size)
{
    for (int i = size - 1; i >= 0; i--)
    {
        printf("%d", binaryForm[i]);
        if (i % 8 == 0)
        {
            printf(" ");
        }
    }
    printf("\n");
}

void getRandomNumber(Number* number)
{
    srand(time(NULL));
    for (int i = 0; i < 8; i++)
    {
        number->binaryForm[i] = (char)(rand() % 256);
    }
}

int main()
{
    Number number;
    getRandomNumber(&number);
    int* binaryFormOfNumber = getBinaryForm(number.binaryForm);

    printBinaryForm(binaryFormOfNumber, sizeOfDouble);

    int* binaryFormOfMantissa = getMantissaBinaryForm(binaryFormOfNumber);
    printf("%13c", ' ');
    printBinaryForm(binaryFormOfMantissa, 52);

    int* binaryFormOfExponent = getExponentBinaryForm(binaryFormOfNumber);
    printf("%c", ' ');
    printBinaryForm(binaryFormOfExponent, 11);

    printf("%d\n", isPositive(binaryFormOfNumber));
}