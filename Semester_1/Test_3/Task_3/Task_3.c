#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int** graphInit(int numberOfLines, int numberOfColumns)
{
    int** graph = malloc(sizeof(int*) * numberOfLines);
    for (int i = 0; i < numberOfLines; i++)
    {
        graph[i] = calloc(numberOfColumns, sizeof(int));
    }

    for (int i = 0; i < numberOfLines; i++)
    {
        for (int j = 0; j < numberOfColumns; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    return graph;
}

bool** isReachableInit(int numberOfLines)
{
    bool** matrix = malloc(sizeof(bool*) * numberOfLines);
    for (int i = 0; i < numberOfLines; i++)
    {
        matrix[i] = calloc(numberOfLines, sizeof(bool));
    }

    for (int i = 0; i < numberOfLines; i++)
    {
        matrix[i][i] = true;
    }

    return matrix;
}

void deleteGraph(int numberOfLines, int** graph)
{
    for (int i = 0; i < numberOfLines; i++)
    {
        free(graph[i]);
    }
    free(graph);
}

void deleteIsReachable(int numberOfLines, bool** matrix)
{
    for (int i = 0; i < numberOfLines; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
}

int main()
{
    int numberOfLines = 0;
    printf("Enter the number of lines:\n");
    scanf("%d", &numberOfLines);
    if (numberOfLines < 1)
    {
        printf("Error. Enter correct number (> 0)");
    }

    int numberOfColumns = 0;
    printf("Enter the number of columns:\n");
    scanf("%d", &numberOfColumns);
    if (numberOfColumns < 1)
    {
        printf("Error. Enter correct number (> 0)");
    }

    printf("Enter the matrix:\n");
    int** graph = graphInit(numberOfLines, numberOfColumns);
    bool** isReachable = isReachableInit(numberOfLines);
    for (int i = 0; i < numberOfLines; i++)
    {
        for (int j = 0; j < numberOfColumns; j++)
        {
            if (graph[i][j] == 1)
            {
                for (int k = 0; k < numberOfLines; k++)
                {
                    if (graph[k][j] == -1 && k != i)
                    {
                        isReachable[i][k] = true;
                    }
                }
            }
        }
    }

/*    for (int i = 0; i < numberOfLines; i++)
    {
        for (int j = 0; j < numberOfColumns; j++)
        {
            printf("%d ", isReachable[i][j]);
        }
        printf("\n");
    }*/

    for (int i = 0; i < numberOfLines; i++)
    {
        for (int j = 0; j < numberOfLines; j++)
        {
            if (isReachable[i][j] && i != j)
            {
                for (int k = 0; k < numberOfLines; k++)
                {
                    isReachable[i][k] = true;
                }
            }
        }
    }

    printf("Reachable nodes:\n");
    int numberOfReachableNodes = 0;
    for (int i = 0; i < numberOfLines; i++)
    {
        int count = 0;
        for (int j = 0; j < numberOfLines; j++)
        {
            if (isReachable[i][j])
            {
                count++;
            }
        }

        if (count == numberOfLines)
        {
            printf("%d ", i + 1);
            numberOfReachableNodes++;
        }
    }

    if (numberOfReachableNodes == 0)
    {
        printf("Doesn't exists");
    }

    deleteGraph(numberOfLines, graph);
    deleteIsReachable(numberOfLines, isReachable);
    return 0;
}

/*
 * 1 0 0 0 1 0 0
1 1 0 0 0 1 0
0 1 1 0 0 0 0
0 0 1 1 0 0 1
0 0 0 1 1 1 0
0 0 0 0 0 0 1
 *
 */