#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void swap(int *array_a, int *array_b)
{
    int temp = *array_a;
    *array_a = *array_b;
    *array_b = temp;
}

int main()
{
    int size = 0;
    printf("Enter the size of array:");
    scanf("%d", &size);

    int *arrayOfNumbers = malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++)
    {
        arrayOfNumbers[i] = 0;
    }
    printf("Enter the array:");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arrayOfNumbers[i]);
    }

    int i = 0;
    int j = size - 1;
    while (true)
    {
        while (i < size && arrayOfNumbers[i] == 0)
        {
            i++;
        }

        if (i >= j)
        {
            break;
        }

        while (j < size && arrayOfNumbers[j] != 0)
        {
            j--;
        }

        swap(&arrayOfNumbers[i++], &arrayOfNumbers[j--]);
    }


    printf("Desired array: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arrayOfNumbers[i]);
    }

    free(arrayOfNumbers);
    return 0;
}
