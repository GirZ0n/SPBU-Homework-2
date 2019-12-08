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

bool getNumberOfCities(int* numberOfCities, FILE* input)
{
    if (fscanf(input, "%d", numberOfCities) != 1 || *numberOfCities < 1)
    {
        return false;
    }

    return true;
}

bool getNumberOfRoads(int* numberOfRoads, FILE* input)
{
    if (fscanf(input, "%d", numberOfRoads) != 1 || *numberOfRoads < 1)
    {
        return false;
    }

    return true;
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

bool getNumberOfCapitals(int* numberOfCapitals, int numberOfCities, FILE* input)
{
    if (fscanf(input, "%d", numberOfCapitals) != 1 || *numberOfCapitals < 1 ||
        *numberOfCapitals > numberOfCities)
    {
        return false;
    }

    return true;
}

bool getCapital(int* capital, int numberOfCities, FILE* input)
{
    if (fscanf(input, "%d", capital) != 1 || *capital < 1 || *capital > numberOfCities)
    {
        return false;
    }

    return true;
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
    if (getNumberOfCities(&numberOfCities, input) == false)
    {
        printf("Invalid number of cities.");
        return 0;
    }

    int numberOfRoads = 0;
    if (getNumberOfRoads(&numberOfRoads, input) == false)
    {
        printf("Invalid number of roads.");
        return 0;
    }

    int** distanceBetweenCities =
            createMatrix(numberOfCities + 1, numberOfCities + 1, INT_MAX);
    int cityA = 0;
    int cityB = 0;
    int length = 0;
    for (int i = 0; i < numberOfRoads; i++)
    {
        if (getCitiesAndDistance(&cityA, &cityB, &length, numberOfCities, input) == false)
        {
            printf("Invalid line.");
            return 0;
        }
        distanceBetweenCities[cityA][cityB] = length;
        distanceBetweenCities[cityB][cityA] = length;
    }

    int numberOfCapitals = 0;
    if (getNumberOfCapitals(&numberOfCapitals, numberOfCities, input) == false)
    {
        printf("Invalid number of capitals.");
        return 0;
    }

    bool* isCityFree = calloc(sizeof(bool), numberOfCities + 1);
    int numberOfUnusedCities = numberOfCities - numberOfCapitals;

    int** states = createMatrix(numberOfCapitals, numberOfCities - numberOfCapitals + 1, 0);
    int capital = 0;
    for (int i = 0; i < numberOfCapitals; i++)
    {
        if (getCapital(&capital, numberOfCities, input) == false)
        {
            printf("Invalid capital.");
            return 0;
        }
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
    fclose(input);
    return 0;
}