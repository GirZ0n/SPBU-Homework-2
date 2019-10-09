#include <stdio.h>
#include <stdlib.h>

void swap(int *elementA, int *elementB)
{
    int temp = *elementA;
    *elementA = *elementB;
    *elementB = temp;
}

void buildHeap(int *array)
{
    return;
}

void siftDown()
{
    return;
}

void heapSort(int *heap)
{
    buildHeap(heap);
    int heapSize = sizeof(heap) / sizeof(heap[0]);
    for (int i = 0; i < heapSize - 2; i++)
    {
        swap(&heap[0], &heap[heapSize - 1 - i]);
        heapSize--;
        siftDown(heap, 0, heapSize);
    }
}

int main() {
    int size = 0;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int *inputArray = malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++)
    {
        inputArray[i] = 0;
    }
    printf("Enter the array: ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &inputArray[i]);
    }

    heapSort(inputArray);

    printf("Sorted array: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", inputArray[i]);
    }

    return 0;
}