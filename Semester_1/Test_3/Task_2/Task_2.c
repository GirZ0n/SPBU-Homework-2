#include <stdio.h>
#include <stdlib.h>

double** createArray(int numberOfLines, int numberOfColumns)
{
    double** array = malloc(numberOfLines * sizeof(double*));
    for (int i = 0; i < numberOfLines; i++)
    {
        array[i] = calloc(numberOfColumns, sizeof(double));
    }
    return array;
}

void deleteArray(int numberOfLines, double** array)
{
    for (int i = 0; i < numberOfLines; i++)
    {
        free(array[i]);
    }
    free(array);
}

double getMinimum(double elementA, double elementB)
{
    return elementA < elementB ? elementA : elementB;
}

double getMinimumInLine(int indexOfLine, int numberOfColumns, double** array)
{
    double minimumInLine = array[indexOfLine][0];
    for (int j = 1; j < numberOfColumns; j++)
    {
        minimumInLine = getMinimum(minimumInLine, array[indexOfLine][j]);
    }
    return minimumInLine;
}

double getMaximum(double elementA, double elementB)
{
    return elementA > elementB ? elementA : elementB;
}

double getMaximumInColumn(int numberOfLines, int indexOfColumn, double** array)
{
    double maximumInColumn = array[0][indexOfColumn];
    for (int i = 1; i < numberOfLines; i++)
    {
        maximumInColumn = getMaximum(maximumInColumn, array[i][indexOfColumn]);
    }
    return maximumInColumn;
}

int main()
{
    int numberOfLines = 0;
    printf("Enter the number of lines:\n");
    scanf("%d", &numberOfLines);

    if (numberOfLines < 1)
    {
        printf("Error. Enter the correct number (> 0).");
        return 0;
    }

    int numberOfColumns = 0;
    printf("Enter the number of columns:\n");
    scanf("%d", &numberOfColumns);

    if (numberOfColumns < 1)
    {
        printf("Error. Enter the correct number (> 0).");
        return 0;
    }

    double** array = createArray(numberOfLines, numberOfColumns);
    printf("Enter the array: \n");
    for (int i = 0; i < numberOfLines; i++)
    {
        for (int j = 0; j < numberOfColumns; j++)
        {
            scanf("%lf", &array[i][j]);
        }
    }

    printf("Saddle points:\n");
    double minimumInLine = 0;
    double maximumInColumn = 0;
    int count = 0;
    for (int i = 0; i < numberOfLines; i++)
    {
        minimumInLine = getMinimumInLine(i, numberOfColumns, array);
        for (int j = 0; j < numberOfColumns; j++)
        {
            maximumInColumn = getMaximumInColumn(numberOfLines, j, array);
            if (array[i][j] == minimumInLine && array[i][j] == maximumInColumn)
            {
                printf("%lf (%d:%d)\n", array[i][j], i, j);
                count++;
            }
        }
    }

    if (count == 0)
    {
        printf("There are no such points.");
    }

    deleteArray(numberOfLines, array);
    return 0;
}