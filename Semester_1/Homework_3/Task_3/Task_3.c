#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void swap(int *array_a, int *array_b)
{
    int temp = *array_a;
    *array_a = *array_b;
    *array_b = temp;
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

bool checkNumber(int number, bool isCorrect)
{
    if (!isCorrect)
    {
        printf("Input Error. ");
        return false;
    }

    if (number < 0)
    {
        printf("Need a positive number. ");
        return false;
    }

    return true;
}

void getSize(int* size)
{
    bool isCorrect = scanf("%d", size);
    if (checkNumber(*size, isCorrect) == false)
    {
        do
        {
            cleanStdin();
            printf("Enter the correct number: ");
            isCorrect = scanf("%d", size);
        }
        while (checkNumber(*size, isCorrect) == false);
    }
}

void getArrayElement(int* arrayElement)
{
    bool isCorrect = scanf("%d", arrayElement);
    if (checkNumber(*arrayElement, isCorrect) == false)
    {
        do
        {
            cleanStdin();
            printf("Enter the correct number: ");
            isCorrect = scanf("%d", arrayElement);
        }
        while (checkNumber(*arrayElement, isCorrect) == false);
    }
}

int main()
{
    int size = 0;
    printf("Enter the size of array: ");
    getSize(&size);

    int *arrayOfNumbers = malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++)
    {
        arrayOfNumbers[i] = 0;
    }
    printf("Enter the array: ");
    for (int i = 0; i < size; i++)
    {
        getArrayElement(&arrayOfNumbers[i]);
    }

    int i = 0;
    int j = size - 1;
    while (i < j)
    {
        while (i < size && arrayOfNumbers[i] == 0)
        {
            i++;
        }

        while (j >= 0 && arrayOfNumbers[j] != 0)
        {
            j--;
        }

        if (i < j)
        {
            swap(&arrayOfNumbers[i++], &arrayOfNumbers[j--]);
        }
    }

    printf("Desired array: ");
    for (int k = 0; k < size; k++)
    {
        printf("%d ", arrayOfNumbers[k]);
    }

    free(arrayOfNumbers);
    return 0;
}
