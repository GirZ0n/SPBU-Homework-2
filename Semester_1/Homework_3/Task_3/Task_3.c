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

bool checkSize(int size, bool isCorrect)
{
    if (!isCorrect)
    {
        printf("Input Error. ");
        return false;
    }

    if (size < 1)
    {
        printf("Need a number >= 1. ");
        return false;
    }

    return true;
}

void getSize(int* size)
{
    bool isCorrect = scanf("%d", size);
    if (checkSize(*size, isCorrect) == false)
    {
        do
        {
            cleanStdin();
            printf("Enter the correct number: ");
            isCorrect = scanf("%d", size);
        }
        while (checkSize(*size, isCorrect) == false);
    }
}

bool checkArrayElement(int arrayElement, bool isCorrect)
{
    if (!isCorrect)
    {
        printf("Input Error. ");
        return false;
    }

    return true;
}

void getArray(int size, int* array)
{
    bool isCorrect = true;
    for (int i = 0; i < size; i++)
    {
        isCorrect = scanf("%d", &array[i]);
        if (checkArrayElement(array[i], isCorrect) == false)
        {
            printf("Re-enter the array: ");
            i = -1;
            cleanStdin();
            continue;
        }
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
    getArray(size, arrayOfNumbers);

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
