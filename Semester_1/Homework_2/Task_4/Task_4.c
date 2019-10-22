#include <stdio.h>
#include <stdlib.h>

int compare(const int *a, const int *b)
{
    return *a - *b;
}

int main()
{
    int sizeOfArray = 0;
    printf("Enter the size of the array:");
    scanf("%d", &sizeOfArray);

    printf("Enter the array:");
    int *arrayOfNumbers = malloc(sizeOfArray * sizeof(int));
    for (int i = 0; i < sizeOfArray; i++)
    {
        scanf("%d", &arrayOfNumbers[i]);
    }

    qsort(arrayOfNumbers, sizeOfArray, sizeof(int), compare);

    for (int i = sizeOfArray - 1; i > 1; i--)
    {
        if (arrayOfNumbers[i] == arrayOfNumbers[i - 1])
        {
            printf("Desired element: %d", arrayOfNumbers[i]);
            free(arrayOfNumbers);
            return 0;
        }
    }

    printf("Element doesn't exist :(");
    free(arrayOfNumbers);
    return 0;
}
