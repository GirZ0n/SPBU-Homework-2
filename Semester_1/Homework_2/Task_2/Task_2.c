#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Fraction
{
    int numerator;
    int denominator;
    double value;
};

struct Fraction createFraction(int numerator, int denominator)
{
    struct Fraction currentFraction;
    currentFraction.numerator = numerator;
    currentFraction.denominator = denominator;
    currentFraction.value= (double) numerator / denominator;
    return currentFraction;
}

int getGreatestCommonDivisor(int firstNumber, int secondNumber)
{
    int remainder = firstNumber % secondNumber;

    if (remainder == 0) 
    {
        return secondNumber;
    }

    return getGreatestCommonDivisor(secondNumber, remainder);
}

bool areMutuallyPrime(int numerator, int denominator)
{
    return getGreatestCommonDivisor(numerator, denominator) == 1;
}

int comparator(const struct Fraction *leftFraction, const struct Fraction *rightFraction)
{
    return leftFraction->value > rightFraction->value;
}


int main() {
    int inputDenominator = 0;
    printf("Enter the denominator:");
    scanf("%d", &inputDenominator);

    int capacity = 1;
    int size = 0;
    struct Fraction *arrayOfFractions = malloc(sizeof(struct Fraction) * capacity);
    arrayOfFractions[0] = createFraction(0, 0);

    for (int currentDenominator = 2; currentDenominator <= inputDenominator; currentDenominator++)
    {
        for (int currentNumerator = 1; currentNumerator < currentDenominator; currentNumerator++)
        {
            if (areMutuallyPrime(currentDenominator, currentNumerator))
            {
                if (size + 1 > capacity)
                {
                    capacity *= 2;
                    arrayOfFractions = realloc(arrayOfFractions, sizeof(struct Fraction) * capacity);
                }

                arrayOfFractions[size] = createFraction(currentNumerator, currentDenominator);
                size++;
            }
        }
    }

    qsort(arrayOfFractions, size, sizeof(struct Fraction), comparator);

    printf("All simple irreducible fractions in the interval (0, 1):\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d/%d ; ", arrayOfFractions[i].numerator, arrayOfFractions[i].denominator);
    }

    free(arrayOfFractions);
    return 0;
}
