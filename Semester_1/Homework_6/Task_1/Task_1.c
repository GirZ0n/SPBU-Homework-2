#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define sizeOfDouble 8 * 8
#define sizeOfMantissa 52
#define sizeOfExponent 11

typedef union Number Number;

union Number
{
    double value;
    char binaryForm[8];
};

bool* createArray(int size)
{
    bool* array = malloc(sizeof(bool) * size);
    for (int i = 0; i < size; i++)
    {
        array[i] = 0;
    }
    return array;
}

bool* getBinaryFormOfNumber(char* number)
{
    bool* binaryForm = createArray(sizeOfDouble);
    for (int i = 0; i < 8; i ++)
    {
        for (int j = 0; j < 8; j++)
        {
            binaryForm[i * 8 + j] = number[i] >> j & 1;
        }
    }
    return binaryForm;
}

bool* getBinaryFormOfMantissa(bool* binaryFormOfNumber)
{
    bool* binaryFormOfMantissa = createArray(sizeOfMantissa);
    for (int i = 0; i < sizeOfMantissa; i++)
    {
        binaryFormOfMantissa[i] = binaryFormOfNumber[i];
    }
    return binaryFormOfMantissa;
}

bool* getBinaryFormOfExponent(bool* binaryFormOfNumber)
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
    return exponent - ((int)pow(2, sizeOfExponent - 1) - 1);
}

double getMantissa(bool* binaryFormOfNumber)
{
    bool* binaryFormOfMantissa = getBinaryFormOfMantissa(binaryFormOfNumber);
    double mantissa = 0;
    for (int i = 0; i < sizeOfMantissa; i++)
    {
        mantissa += binaryFormOfMantissa[sizeOfMantissa - 1 - i] * pow(2, -(i + 1));
    }
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

int main()
{
    Number number;
    printf("Enter the number: ");
    scanf("%lf", &number.value);

    bool* binaryFormOfNumber = getBinaryFormOfNumber(number.binaryForm);
    double mantissa = getMantissa(binaryFormOfNumber) + 1;
    int exponent = getExponent(binaryFormOfNumber);
    if (isNegative(binaryFormOfNumber))
    {
        mantissa *= -1;
    }

    printf("Scientific notation: %.10lf * 2^(%d)", mantissa, exponent);
    return 0;
}