#include <stdio.h>

const int maxSize = 256;

void swap(int array[], int indexA, int indexB)
{
    int temp = array[indexA];
    array[indexA] = array[indexB];
    array[indexB] = temp;
}

void reverse(int array[], int begin, int end)
{
    int lengthOfSegment = end - begin;
    for (int i = 0; i < lengthOfSegment / 2; i++)
    {
        swap(array, begin + i, end - i - 1);
    }
}

int main()
{
    int n = 0;
    int m = 0;
    printf("Enter the value of N:");
    scanf("%d", &n);
    printf("Enter the value of M:");
    scanf("%d", &m);

    int array[maxSize] = {0};
    printf("Enter array: ");
    for (int i = 0; i < n + m; i++)
    {
        scanf("%d", &array[i]);
    }

    reverse(array, 0, n);
    reverse(array, n, n + m);
    reverse(array, 0, n + m);

    printf("Result:");
    for (int i = 0; i < n + m; i++)
    {
        printf("%d ", array[i]);
    }

    return 0;
}
