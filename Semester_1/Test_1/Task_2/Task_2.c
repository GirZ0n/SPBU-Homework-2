#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

void getRandomArray(int *array, int size)
{
    srand(time(NULL));
    for (int i = 0; i < size; i++)
    {
        array[i] = 11 + rand() % 32;
    }
}

void swap(int *elementA, int *elementB)
{
    int temp = *elementA;
    *elementA = *elementB;
    *elementB = temp;
}

void insertionSort(int *array, int size)
{
    for (int i = 2; i < size; i += 2)
    {
        for (int j = i; j > 0; j -= 2)
        {
            if (array[j - 2] > array[j])
            {
                swap(&array[j - 2], &array[j]);
            }
        }
    }
}

int main() {
    int size = 0;
    int capacity = 1;
    int *array = malloc(sizeof(int) * capacity);

    int choice = 0;
    printf("How do you want to enter an array? (0 - Console, 1 - Automatic generation): ");
    scanf("%d", &choice);
    if (choice == 0)
    {
        printf("Enter the array: ");
        while (true)
        {
            int input = 0;
            scanf("%d", &input);

            if (input == 0)
            {
                break;
            }

            if (size + 1 > capacity)
            {
                capacity *= 2;
                array = realloc(array, sizeof(int) * capacity);
            }

            array[size] = input;
            size++;
        }
    }
    else
    {
        printf("Enter the size of the array: ");
        scanf("%d", &size);
        array = malloc(sizeof(int) * size);
        getRandomArray(array, size);
        printf("Random array: ");
        for (int i = 0; i < size; i++)
        {
            printf("%d ", array[i]);
        }
        printf("\n");
    }

    printf("Sorted array: ");
    insertionSort(array, size);
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }

    free(array);
    return 0;
}
