#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void swap(int* elementA, int* elementB)
{
    int temp = *elementA;
    *elementA = *elementB;
    *elementB = temp;
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

bool checkSize(int size, int numberOfVariablesRead)
{
    return numberOfVariablesRead == 1 && size > 0;
}

void getSize(int* size)
{
    int numberOfVariablesRead = scanf("%d", size);
    while (checkSize(*size, numberOfVariablesRead) == false)
    {
        cleanStdin();
        printf("Enter the correct size of array:\n");
        numberOfVariablesRead = scanf("%d", size);
    }
    cleanStdin();
}

void getArray(int size, int* array)
{
    for (int i = 0; i < size; i++)
    {
        int numberOfVariablesRead = scanf("%d", &array[i]);
        if (numberOfVariablesRead != 1)
        {
            printf("Input Error. Re-enter the array:\n");
            cleanStdin();
            i = -1;
            continue;
        }
    }
}

int main()
{
    int size = 0;
    printf("Enter the size of array (number > 0):\n");
    getSize(&size);

    int *arrayOfNumbers = calloc(sizeof(int), size);
    printf("Enter the array (the element must be a number):\n");
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

    printf("Desired array:\n");
    for (int k = 0; k < size; k++)
    {
        printf("%d ", arrayOfNumbers[k]);
    }

    free(arrayOfNumbers);
    return 0;
}
