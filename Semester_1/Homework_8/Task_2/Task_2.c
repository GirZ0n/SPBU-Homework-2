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

int getNumberOfNearestCity(int indexOfCurrentCapital, int** states, int** distanceBetweenCities, bool* isCityFree,
        int numberOfCities, int numberOfCapitals)
{
    int minimumDistance = INT_MAX;
    int numberOfTheNearestCity = INT_MAX;
    int iterator = 0;
    int currentCityInState = states[indexOfCurrentCapital][iterator];
    while (iterator < numberOfCities - numberOfCapitals && currentCityInState != 0)
    {
        currentCityInState = states[indexOfCurrentCapital][iterator];
        for (int currentCity = 1; currentCity < numberOfCities + 1; currentCity++)
        {
            if (!isCityFree[currentCity])
            {
                if (distanceBetweenCities[currentCityInState][currentCity] < minimumDistance)
                {
                    minimumDistance = distanceBetweenCities[currentCityInState][currentCity];
                    numberOfTheNearestCity = currentCity;
                }
            }
        }
        iterator++;
    }

    return numberOfTheNearestCity;
}

bool getNumber(int* number, FILE* input)
{
    return fscanf(input, "%d", number) == 1 && *number > 0;
}

bool getCitiesAndDistance(int* cityA, int* cityB, int* distance, int numberOfCities, FILE* input)
{
    if (fscanf(input,"%d %d %d", cityA, cityB, distance) == 3 && *cityA > 0 && *cityB > 0 &&
        *cityA != *cityB && *cityA <= numberOfCities && *cityB <= numberOfCities && *distance > 0)
    {
        return true;
    }

    return false;
}

bool graphInitialization(int numberOfRoads, int numberOfCities, int** graph, FILE* input)
{
    int cityA = 0;
    int cityB = 0;
    int length = 0;
    for (int i = 0; i < numberOfRoads; i++)
    {
        if (getCitiesAndDistance(&cityA, &cityB, &length, numberOfCities, input) == false)
        {
            return false;
        }
        graph[cityA][cityB] = length;
        graph[cityB][cityA] = length;
    }

    return true;
}

bool statesInitialization(int numberOfCapitals, int numberOfCities, bool* isCityFree, int** states, FILE* input)
{
    int capital = 0;
    for (int i = 0; i < numberOfCapitals; i++)
    {
        if (getNumber(&capital, input) == false || capital > numberOfCities)
        {
            return false;
        }
        states[i][0] = capital;
        isCityFree[capital] = true;
    }

    return true;
}

void outputResult(int numberOfCapitals, int** states)
{
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
}

void cityDistribution(int* numberOfUnusedCities, int numberOfCities, int numberOfCapitals, int** states,
                      int** distanceBetweenCities, bool* isCityFree)
{
    int iterator = 0;
    int indexOfCurrentCapital = 0;
    while (*numberOfUnusedCities != 0)
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

        (*numberOfUnusedCities)--;
        iterator++;
    }
}

int main()
{
    FILE* input = fopen("input.txt", "r");
    if (input == NULL)
    {
        printf("Can't open the file.");
        return 0;
    }

    int numberOfCities = 0;
    if (!getNumber(&numberOfCities, input))
    {
        printf("Invalid number of cities.");
        return 0;
    }

    int numberOfRoads = 0;
    if (!getNumber(&numberOfRoads, input))
    {
        printf("Invalid number of roads.");
        return 0;
    }

    int** distanceBetweenCities =
            createMatrix(numberOfCities + 1, numberOfCities + 1, INT_MAX);
    if (!graphInitialization(numberOfRoads, numberOfCities, distanceBetweenCities, input))
    {
        printf("Invalid line.");
        deleteMatrix(distanceBetweenCities, numberOfCities + 1);
        return 0;
    }

    int numberOfCapitals = 0;
    if (!getNumber(&numberOfCapitals, input) || numberOfCapitals > numberOfCities)
    {
        printf("Invalid number of capitals.");
        deleteMatrix(distanceBetweenCities, numberOfCities + 1);
        return 0;
    }

    bool* isCityFree = calloc(sizeof(bool), numberOfCities + 1);
    int numberOfUnusedCities = numberOfCities - numberOfCapitals;

    int** states = createMatrix(numberOfCapitals, numberOfCities - numberOfCapitals + 1, 0);
    if (!statesInitialization(numberOfCapitals, numberOfCities, isCityFree, states, input))
    {
        printf("Invalid capital.");
        deleteMatrix(distanceBetweenCities, numberOfCities + 1);
        free(isCityFree);
        deleteMatrix(states, numberOfCapitals);
        return 0;
    }

    cityDistribution(&numberOfUnusedCities, numberOfCities, numberOfCapitals, states,
                     distanceBetweenCities, isCityFree);

    outputResult(numberOfCapitals, states);

    deleteMatrix(distanceBetweenCities, numberOfCities + 1);
    free(isCityFree);
    deleteMatrix(states, numberOfCapitals);
    fclose(input);
    return 0;
}