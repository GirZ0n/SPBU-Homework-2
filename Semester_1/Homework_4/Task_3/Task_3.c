#include <stdio.h>
#include <stdlib.h>

int main() {
    int size = 0;
    printf("Enter the size of the matrix: ");
    scanf("%d", &size);

    printf("Enter the matrix: ");
    int **matrix = malloc(sizeof(int*) * size);
    for (int i = 0; i < size; i++)
    {
        matrix[i] = malloc(sizeof(int) * size);
        for (int j = 0; j < size; j++)
        {
            matrix[i][j] = 0;
        }
        for (int j = 0; j < size; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    int movementX[4] = {0, 1, 0, -1};
    int movementY[4] = {-1, 0, 1, 0};

    int currentPathLength = 1;
    int coordinateX = size / 2;
    int coordinateY = size / 2;
    for (int i = 0; i < size * 2 - 2; i++)
    {
        if (i != 0 && i % 2 == 0)
        {
            currentPathLength++;
        }

        int currentMovementX = movementX[i % 4];
        int currentMovementY = movementY[i % 4];
        for (int j = 0; j < currentPathLength; j++)
        {
            printf("%d ", matrix[coordinateY][coordinateX]);
            coordinateX += movementX[i];
            coordinateY += movementY[i];
        }
    }

    for (int j = 0; j < size; j++)
    {
        printf("%d ", matrix[coordinateY--][coordinateX]);
    }

    for (int i = 0; i < size; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
    return 0;
}