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

    int *array = malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++)
    {
        array[i] = 0;
    }
    printf("Enter the array:");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &array[i]);
    }


    int i = 0;
    int j = size - 1;
    while(true)
    {
        while(array[i] == 0)
        {
            i++;
        }

        while(array[j] != 0)
        {
            j--;
        }

        if (i >= j)
        {
            break;
        }

        swap(&array[i++], &array[j--]);
    }

    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
}