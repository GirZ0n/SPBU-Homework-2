#include <stdio.h>
#include <stdlib.h>

int byAscendingOrder(const void* left, const void* right)
{
    return *(int*) left - *(int*) right;
}

int* expand(int* capacity, int* array)
{
    int* newArray = calloc(*capacity * 2, sizeof(int));
    for (int i = 0; i < *capacity; i++)
    {
        newArray[i] = array[i];
    }
    free(array);
    *capacity *= 2;
    return newArray;
}

int main()
{
    int input = -1;
    printf("Enter array:\n");
    int size = 0;
    int capacity = 2;
    int* array = calloc(capacity, sizeof(int));
    while (input != 0)
    {
        scanf("%d", &input);

        if (input == 0)
        {
            break;
        }

        if (size == capacity)
        {
            array = expand(&capacity, array);
        }

        array[size++] = input;
    }

    qsort(array, size, sizeof(int), byAscendingOrder);

    printf("Result:\n");
    printf("Form: number - amount\n");
    int currentNumber = array[0];
    int currentCount = 1;
    for (int i = 1; i < size; i++)
    {
        if (array[i] == currentNumber)
        {
            currentCount++;
        }
        else
        {
            printf("%d - %d\n", currentNumber, currentCount);
            currentNumber = array[i];
            currentCount = 1;
        }
    }
    printf("%d - %d\n", currentNumber, currentCount);

    free(array);
}