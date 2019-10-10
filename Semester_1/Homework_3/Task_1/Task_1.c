#include <stdio.h>
#include <stdlib.h>

void swap(int *elementA, int *elementB)
{
    int temp = *elementA;
    *elementA = *elementB;
    *elementB = temp;
}

void heapify(int *array, int heapSize, int rootIndex)
{
    int indexOfLargestElement = rootIndex;
    int indexOfLeftChild = 2 * rootIndex + 1;
    int indexOfRightChild = 2 * rootIndex + 2;

    if (indexOfLeftChild < heapSize && array[indexOfLeftChild] > array[indexOfLargestElement])
    {
        indexOfLargestElement = indexOfLeftChild;
    }

    if (indexOfRightChild < heapSize && array[indexOfRightChild] > array[indexOfLargestElement])
    {
        indexOfLargestElement = indexOfRightChild;
    }

    if (indexOfLargestElement != rootIndex)
    {
        swap(&array[rootIndex], &array[indexOfLargestElement]);
        heapify(array, heapSize, indexOfLargestElement);
    }
}

void createHeap(int *array, int heapSize)
{
    for (int i = heapSize / 2 - 1; i >= 0; i--)
    {
        heapify(array, heapSize, i);
    }
}

void heapSort(int *heap, int heapSize)
{
    for (int i = heapSize - 1; i >= 0; i--)
    {
        swap(&heap[0], &heap[i]);
        heapify(heap, i, 0);
    }
}

int *createArray(int arraySize)
{
    int *array = malloc(sizeof(int) * arraySize);
    for (int i = 0; i < arraySize; i++)
    {
        array[i] = 0;
    }

    return array;
}

void printArray(int *array, int arraySize)
{
    for (int i = 0; i < arraySize; i++)
    {
        printf("%d ", array[i]);
    }
}

int main()
{
    int arraySize = 0;
    printf("Enter the size of the array: ");
    scanf("%d", &arraySize);

    int *inputArray = createArray(arraySize);
    printf("Enter the array: ");
    for (int i = 0; i < arraySize; i++)
    {
        scanf("%d", &inputArray[i]);
    }

    createHeap(inputArray, arraySize);
    heapSort(inputArray, arraySize);

    printf("Sorted array: ");
    printArray(inputArray, arraySize);
    
    free(inputArray);
    return 0;
}
