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

int** createReachabilityMatrix(int numberOfLines)
{
    int** matrix = malloc(sizeof(int*) * numberOfLines);
    for (int i = 0; i < numberOfLines; i++)
    {
        matrix[i] = malloc(sizeof(int*) * (numberOfLines - 1));
        for (int j = 0; j < numberOfLines - 1; j++)
        {
            matrix[i][j] = -1;
        }
    }
    return matrix;
}

void deleteMatrix(int numberOfLines, int** graph)
{
    for (int i = 0; i < numberOfLines; i++)
    {
        free(graph[i]);
    }
    free(graph);
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
    int** reachabilityMatrix = createReachabilityMatrix(numberOfLines);
    for (int i = 0; i < numberOfLines; i++)
    {
        int currentPosition = 0;
        for (int j = 0; j < numberOfColumns; j++)
        {
            if (graph[i][j] == 1)
            {
                for (int k = 0; k < numberOfLines; k++)
                {
                    if (graph[k][j] == 1 && k != i)
                    {
                        reachabilityMatrix[i][currentPosition] = k;
                        currentPosition++;
                    }
                }
            }
        }
    }

    for (int i = 0; i < numberOfLines; i++)
    {
        for (int j = 0; j < numberOfLines - 1; j++)
        {
            printf("%d ", reachabilityMatrix[i][j]);
        }
        printf("\n");
    }

    bool* isReachable = calloc(numberOfLines, sizeof(bool));
    for (int i = 0; i < numberOfLines; i++)
    {
        for (int j = 0; j < numberOfLines - 1; j++)
        {
            int currentNode = reachabilityMatrix[i][j];

            if (isReachable[currentNode])
            {
                isReachable[i] = true;
            }

            if (currentNode != -1)
            {
                for (int k = 0; k < numberOfLines - 1; k++)
                {
                    int currentCheckNode = reachabilityMatrix[currentNode][k];
                    int l = 0;
                    if (currentCheckNode != -1)
                    {
                        for (l = 0; l < numberOfLines - 1; l++)
                        {
                            if (currentCheckNode == reachabilityMatrix[i][l])
                            {
                                break;
                            }
                        }
                    }

                    if (l < numberOfLines - 1 && reachabilityMatrix[i][l] == -1)
                    {
                        reachabilityMatrix[i][l] = currentCheckNode;
                    }
                }
            }
        }

        if (reachabilityMatrix[i][numberOfLines - 1] != -1)
        {
            isReachable[i] = true;
        }
    }

    printf("Reachable nodes:\n");
    for (int i = 0; i < numberOfLines; i++)
    {
        if (isReachable[i])
        {
            printf("%d ", i + 1);
        }
    }

    deleteMatrix(numberOfLines, graph);
    deleteMatrix(numberOfLines, reachabilityMatrix);
    free(isReachable);
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