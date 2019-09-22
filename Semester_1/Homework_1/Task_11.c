#include <stdio.h>

void swap(int array[], int indexA, int indexB)
{
    int temporary = array[indexA];
    array[indexA] = array[indexB];
    array[indexB] = temporary;
}

int partition(int array[], int indexBegin, int indexEnd)
{
    int middle = array[(indexBegin + indexEnd) / 2];
    int i = indexBegin;
    int j = indexEnd;
    while (i < j)
    {
        while (array[i] < middle)
        {
            i++;
        }
        while (array[j] > middle)
        {
            j--;
        }

        if (i >= j)
        {
            break;
        }

        swap(array, i, j);
        i++;
        j--;
    }
    return j;
}

void qsort(int unsortedArray[], int indexBegin, int indexEnd)
{
    if (indexBegin < indexEnd)
    {
        int j = partition(unsortedArray, indexBegin, indexEnd);
        qsort(unsortedArray, indexBegin, j);
        qsort(unsortedArray, j + 1, indexEnd);
    }
}

int main()
{
    int size = 0;
    printf("Enter the size of the array:");
    scanf("%d", &size);
    int unsortedArray[size];
    printf("Enter array:");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &unsortedArray[i]);
    }

    qsort(unsortedArray, 0, size - 1);

    printf("Sorted array: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", unsortedArray[i]);
    }

    return 0;
}