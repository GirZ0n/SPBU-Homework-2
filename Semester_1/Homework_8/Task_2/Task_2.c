#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

int** createMatrix(int numberOfLines, int numberOfColumns, int defaultValue)
{
    int** newMatrix = malloc(sizeof(int*) * numberOfLines);
    for (int i = 0; i < numberOfLines; i++)
    {
        newMatrix[i] = malloc(sizeof(int) * numberOfColumns);
        for (int j = 0; j < numberOfColumns; j++)
        {
            newMatrix[i][j] = defaultValue;
        }
    }
    return newMatrix;
}

void deleteMatrix(int** matrix, int numberOfLines)
{
    for (int i = 0; i < numberOfLines; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
}

void printMatrix(int** matrix, int numberOfLines, int numberOfColumns)
{
    for (int i = 1; i < numberOfLines; i++)
    {
        for (int j = 1; j < numberOfColumns; j++)
        {
            if (matrix[i][j] == INT_MAX)
            {
                printf("0 ");
            }
            else
            {
                printf("%d ", matrix[i][j]);
            }
        }
        printf("\n");
    }
}

int min(int numberA, int numberB)
{
    return numberA < numberB ? numberA : numberB;
}

int getNumberOfNearestCity(int indexOfCurrentCapital, int** states, int** distanceBetweenCities, bool* isCityUsed,
        int numberOfCities, int numberOfCapitals)
{
    int minimumDistance = INT_MAX;
    int numberOfTheNearestCity = INT_MAX;
    int iterator = 0;
    while (iterator < numberOfCities - numberOfCapitals && states[indexOfCurrentCapital][iterator] != 0)
    {
        int currentCity = states[indexOfCurrentCapital][iterator];



        iterator++;
    }
}

int main()
{
    FILE* input = fopen("input.txt", "r");

    int numberOfCities = 0;
    int numberOfRoads = 0;
    fscanf(input,"%d %d", &numberOfCities, &numberOfRoads);

    int** distanceBetweenCities =
            createMatrix(numberOfCities + 1, numberOfCities + 1, INT_MAX);
    int cityA = 0;
    int cityB = 0;
    int length = 0;
    for (int i = 0; i < numberOfRoads; i++)
    {
        fscanf(input,"%d %d %d", &cityA, &cityB, &length);
        distanceBetweenCities[cityA][cityB] = length;
        distanceBetweenCities[cityB][cityA] = length;
    }

    int numberOfCapitals = 0;
    fscanf(input, "%d", &numberOfCapitals);

    int numberOfUnusedCities = numberOfCities - numberOfCapitals;
    bool* isCityUsed = calloc(sizeof(bool), numberOfCities + 1);

    int** states = createMatrix(numberOfCapitals, numberOfCities - numberOfCapitals + 1, 0);
    int capital = 0;
    for (int i = 0; i < numberOfCapitals; i++)
    {
        fscanf(input, "%d", &capital);
        states[i][0] = capital;
        isCityUsed[capital] = true;
    }

    int iterator = 0;
    int indexOfCurrentCapital = 0;
    while (numberOfUnusedCities != 0)
    {
        indexOfCurrentCapital = iterator % numberOfCapitals;

        int numberOfNearestCity = getNumberOfNearestCity(indexOfCurrentCapital, states, distanceBetweenCities,
                isCityUsed, numberOfCities, numberOfCapitals);

        if (numberOfNearestCity == INT_MAX)
        {
            continue;
        }

        int indexOfInsert = 0;
        while (states[indexOfCurrentCapital][indexOfInsert] != 0)
        {
            indexOfInsert++;
        }

        states[indexOfCurrentCapital][indexOfInsert] = numberOfNearestCity;
        isCityUsed[numberOfNearestCity] = true;

        numberOfUnusedCities--;
        iterator++;
    }




    deleteMatrix(distanceBetweenCities, numberOfCities + 1);
    free(isCityUsed);
    deleteMatrix(states, numberOfCapitals);
    if (input != NULL)
    {
        fclose(input);
    }
    return 0;
}