#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

const int sizeOfDouble = 8 * 8;
const int sizeOfMantissa = 52;
const int sizeOfExponent = 11;

typedef union Number Number;

union Number
{
    double value;
    char binaryForm[8];
};

bool* createArray(int size)
{
    bool* array = calloc(sizeof(bool), size);
    return array;
}

bool* getBinaryFormOfNumber(const char* number)
{
    bool* binaryForm = createArray(sizeOfDouble);
    for (int i = 0; i < 8; i ++)
    {
        for (int j = 0; j < 8; j++)
        {
            binaryForm[i * 8 + j] = (int) number[i] >> j & 1;
        }
    }
    return binaryForm;
}

bool* getBinaryFormOfMantissa(const bool* binaryFormOfNumber)
{
    bool* binaryFormOfMantissa = createArray(sizeOfMantissa);
    for (int i = 0; i < sizeOfMantissa; i++)
    {
        binaryFormOfMantissa[i] = binaryFormOfNumber[i];
    }
    return binaryFormOfMantissa;
}

bool* getBinaryFormOfExponent(const bool* binaryFormOfNumber)
{
    bool* binaryFormOfExponent = createArray(sizeOfExponent);
    for (int i = sizeOfMantissa; i < sizeOfDouble - 1; i++)
    {
        binaryFormOfExponent[i - sizeOfMantissa] = binaryFormOfNumber[i];
    }
    return binaryFormOfExponent;
}

int getExponent(bool* binaryFormOfNumber)
{
    bool* binaryFormOfExponent = getBinaryFormOfExponent(binaryFormOfNumber);
    int exponent = 0;
    for (int i = 0; i < sizeOfExponent; i++)
    {
        exponent += binaryFormOfExponent[i] * (int)pow(2, i);
    }
    free(binaryFormOfExponent);
    return exponent - ((int) pow(2, sizeOfExponent - 1) - 1);
}

double getMantissa(bool* binaryFormOfNumber)
{
    bool* binaryFormOfMantissa = getBinaryFormOfMantissa(binaryFormOfNumber);
    double mantissa = 0;
    for (int i = 1; i <= sizeOfMantissa; i++)
    {
        mantissa += binaryFormOfMantissa[sizeOfMantissa - i] * pow(2, -i);
    }
    free(binaryFormOfMantissa);
    return mantissa;
}

bool isNegative(bool* binaryFormOfNumber)
{
    return binaryFormOfNumber[sizeOfDouble - 1];
}

void printBinaryForm(bool* binaryForm, int size)
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

void cleanStdin()
{
    int c;
    do
    {
        c = getchar();
    }
    while (c != EOF && c != '\n');
}

void getInputNumber(double* inputNumber)
{
    int numberOfVariablesRead = scanf("%lf", inputNumber);
    while (numberOfVariablesRead != 1)
    {
        cleanStdin();
        printf("Input Error. Enter the correct number:\n");
        numberOfVariablesRead = scanf("%lf", inputNumber);
    }
    cleanStdin();
}

int main()
{
    Number inputNumber;
    printf("Enter the number:\n");
    getInputNumber(&inputNumber.value);

    bool* binaryFormOfNumber = getBinaryFormOfNumber(inputNumber.binaryForm);
    double mantissa = getMantissa(binaryFormOfNumber) + 1;
    int exponent = getExponent(binaryFormOfNumber);
    if (isNegative(binaryFormOfNumber))
    {
        mantissa *= -1;
    }

    printf("Scientific notation: %.10lf * 2^(%d)", mantissa, exponent);
    free(binaryFormOfNumber);
    return 0;
}