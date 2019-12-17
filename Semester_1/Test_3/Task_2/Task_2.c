#include <stdio.h>
#include <stdlib.h>

int** createArray(int numberOfLines, int numberOfColumns)
{
    int** array = malloc(numberOfLines * sizeof(int*));
    for (int i = 0; i < numberOfLines; i++)
    {
        array[i] = calloc(numberOfColumns, sizeof(int));
    }
    return array;
}

void deleteArray(int numberOfLines, int** array)
{
    for (int i = 0; i < numberOfLines; i++)
    {
        free(array[i]);
    }
    free(array);
}

int getMinimum(int elementA, int elementB)
{
    return elementA < elementB ? elementA : elementB;
}

int getMinimumInLine(int indexOfLine, int numberOfColumns, int** array)
{
    int minimumInLine = array[indexOfLine][0];
    for (int j = 1; j < numberOfColumns; j++)
    {
        minimumInLine = getMinimum(minimumInLine, array[indexOfLine][j]);
    }
    return minimumInLine;
}

int getMaximum(int elementA, int elementB)
{
    return elementA > elementB ? elementA : elementB;
}

int getMaximumInColumn(int numberOfLines, int indexOfColumn, int** array)
{
    int maximumInLine = array[0][indexOfColumn];
    for (int i = 1; i < numberOfLines; i++)
    {
        maximumInLine = getMaximum(maximumInLine, array[i][indexOfColumn]);
    }
    return maximumInLine;
}

int main()
{
    int numberOfLines = 0;
    printf("Enter the number of lines:\n");
    scanf("%d", &numberOfLines);
    int numberOfColumns = 0;
    printf("Enter the number of columns:\n");
    scanf("%d", &numberOfColumns);
    int** array = createArray(numberOfLines, numberOfColumns);
    printf("Enter the array: \n");
    for (int i = 0; i < numberOfLines; i++)
    {
        for (int j = 0; j < numberOfColumns; j++)
        {
            scanf("%d", &array[i][j]);
        }
    }

    printf("Saddle points:\n");
    int minimumInLine = 0;
    int maximumInColumn = 0;
    for (int i = 0; i < numberOfLines; i++)
    {
        minimumInLine = getMinimumInLine(i, numberOfColumns, array);
        for (int j = 0; j < numberOfColumns; j++)
        {
            maximumInColumn = getMaximumInColumn(numberOfLines, j, array);
            if (array[i][j] == minimumInLine && array[i][j] == maximumInColumn)
            {
                printf("%d\n", array[i][j]);
            }
        }
    }

    deleteArray(numberOfLines, array);
    return 0;
}