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
    for (int i = 0; i < numberOfLines; i++)
    {
        for (int j = 0; j < numberOfColumns; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int getNumberOfNearestCity(int indexOfCurrentCapital, int** states, int** distanceBetweenCities, bool* isCityFree,
        int numberOfCities, int numberOfCapitals)
{
    int minimumDistance = INT_MAX;
    int numberOfTheNearestCity = INT_MAX;
    int iterator = 0;
    while (iterator < numberOfCities - numberOfCapitals && states[indexOfCurrentCapital][iterator] != 0)
    {
        int currentCity = states[indexOfCurrentCapital][iterator];
        for (int i = 1; i < numberOfCities; i++)
        {
            if (!isCityFree[i])
            {
                if (distanceBetweenCities[currentCity][i] < minimumDistance)
                {
                    minimumDistance = distanceBetweenCities[currentCity][i];
                    numberOfTheNearestCity = i;
                }
            }
        }
        iterator++;
    }

    return numberOfTheNearestCity;
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

    bool* isCityFree = calloc(sizeof(bool), numberOfCities + 1);
    int numberOfUnusedCities = numberOfCities - numberOfCapitals;

    int** states = createMatrix(numberOfCapitals, numberOfCities - numberOfCapitals + 1, 0);
    int capital = 0;
    for (int i = 0; i < numberOfCapitals; i++)
    {
        fscanf(input, "%d", &capital);
        states[i][0] = capital;
        isCityFree[capital] = true;
    }

    int iterator = 0;
    int indexOfCurrentCapital = 0;
    while (numberOfUnusedCities != 0)
    {
        indexOfCurrentCapital = iterator % numberOfCapitals;

        int numberOfNearestCity = getNumberOfNearestCity(indexOfCurrentCapital, states, distanceBetweenCities,
                                                         isCityFree, numberOfCities, numberOfCapitals);

        if (numberOfNearestCity == INT_MAX)
        {
            iterator++;
            continue;
        }

        int indexOfInsert = 0;
        while (states[indexOfCurrentCapital][indexOfInsert] != 0)
        {
            indexOfInsert++;
        }

        states[indexOfCurrentCapital][indexOfInsert] = numberOfNearestCity;
        isCityFree[numberOfNearestCity] = true;

        numberOfUnusedCities--;
        iterator++;
    }

    printf("On the left is the number of the capital of the state, on the right, through a space,\n");
    printf("the numbers of the city related to this state:\n");
    for (int i = 0; i < numberOfCapitals; i++)
    {
        printf("%d - ", states[i][0]);
        int indexOfCurrentCity = 1;
        while (states[i][indexOfCurrentCity] != 0)
        {
            printf("%d ", states[i][indexOfCurrentCity]);
            indexOfCurrentCity++;
        }

        if (indexOfCurrentCity == 1)
        {
            printf("there are no other cities");
        }

        printf("\n");
    }

    deleteMatrix(distanceBetweenCities, numberOfCities + 1);
    free(isCityFree);
    deleteMatrix(states, numberOfCapitals);
    if (input != NULL)
    {
        fclose(input);
    }
    return 0;
}