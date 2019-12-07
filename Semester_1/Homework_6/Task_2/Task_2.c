#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

const int sizeOfInt = 4 * 8;

int* createArray(int size)
{
    int* array = malloc(sizeOfInt * size);
    for (int i = 0; i < size; i++)
    {
        array[i] = 0;
    }

    return array;
}

int* getBinaryForm(int number)
{
    int* binaryForm = createArray(sizeOfInt);
    for (int i = 0; i < sizeOfInt; i ++)
    {
        binaryForm[i] = number >> i & 1;
    }

    return binaryForm;
}

void printBinaryForm(int* binaryForm)
{
    for (int i = sizeOfInt - 1; i >= 0; i--)
    {
        printf("%d", binaryForm[i]);
        if (i % 8 == 0)
        {
            printf(" ");
        }
    }
    printf("\n");
}

int* getSumInBinaryForm(const int* binaryFormOfNumberA, const int* binaryFormOfNumberB)
{
    int* sumInBinaryForm = createArray(sizeOfInt);

    int carry = 0;
    int currentSum = 0;
    for (int i = 0; i < sizeOfInt; i++)
    {
        currentSum = binaryFormOfNumberA[i] + binaryFormOfNumberB[i] + carry;
        sumInBinaryForm[i] = currentSum % 2;
        carry = currentSum / 2;
    }

    return sumInBinaryForm;
}

int getNumberFromBinaryForm(const int* binaryForm)
{
    int number = 0;
    if (binaryForm[sizeOfInt - 1] == 0)
    {
        for (int i = sizeOfInt - 1; i >= 0; i--)
        {
            number += binaryForm[i] * (int) pow(2, i);
        }
    }
    else
    {
        for (int i = sizeOfInt - 1; i >= 0; i--)
        {
            number += !binaryForm[i] * (int) pow(2, i);
        }
        number++;
        number *= -1;
    }

    return number;
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

void getNumber(int* number)
{
    int isCorrect = scanf("%d", number);
    while (isCorrect != 1)
    {
        cleanStdin();
        printf("Input Error. Enter the correct number:\n");
        isCorrect = scanf("%d", number);
    }
    cleanStdin();
}

int main()
{
    int numberA = 0;
    printf("Enter the number #1:\n");
    getNumber(&numberA);

    int numberB = 0;
    printf("Enter the number #2:\n");
    getNumber(&numberB);

    int* binaryFormOfNumberA = getBinaryForm(numberA);
    int* binaryFormOfNumberB = getBinaryForm(numberB);

    printf("Binary form of number #1: ");
    printBinaryForm(binaryFormOfNumberA);
    printf("Binary form of number #2: ");
    printBinaryForm(binaryFormOfNumberB);

    int* sum = getSumInBinaryForm(binaryFormOfNumberA, binaryFormOfNumberB);
    printf("%6cBinary form of sum: ", ' ');
    printBinaryForm(sum);
    printf("%5cDecimal form of sum: %d", ' ', getNumberFromBinaryForm(sum));

    free(binaryFormOfNumberA);
    free(binaryFormOfNumberB);
    free(sum);
    return 0;
}
