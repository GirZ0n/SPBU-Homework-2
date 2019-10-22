#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Fraction
{
    int numerator;
    int denominator;
};

typedef struct Fraction Fraction;

Fraction createFraction(int numerator, int denominator)
{
    Fraction currentFraction;
    currentFraction.numerator = numerator;
    currentFraction.denominator = denominator;
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

bool areCoprime(int numerator, int denominator)
{
    return getGreatestCommonDivisor(numerator, denominator) == 1;
}

int comparator(const Fraction *leftFraction, const Fraction *rightFraction)
{
    return leftFraction->numerator * rightFraction->denominator - leftFraction->denominator * rightFraction->numerator;
}


int main() {
    int inputDenominator = 0;
    printf("Enter the denominator:");
    scanf("%d", &inputDenominator);

    int capacity = (inputDenominator) * (inputDenominator - 1) / 2;
    int size = 0;
    Fraction *arrayOfFractions = malloc(sizeof(Fraction) * capacity);
    for (int i = 0; i < capacity; i++)
    {
        arrayOfFractions[i] = createFraction(0, 0);
    }

    for (int currentDenominator = 2; currentDenominator <= inputDenominator; currentDenominator++)
    {
        for (int currentNumerator = 1; currentNumerator < currentDenominator; currentNumerator++)
        {
            if (areCoprime(currentDenominator, currentNumerator))
            {
                arrayOfFractions[size] = createFraction(currentNumerator, currentDenominator);
                size++;
            }
        }
    }

    qsort(arrayOfFractions, size, sizeof(Fraction), comparator);

    printf("All simple irreducible fractions in the interval (0, 1):\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d/%d ; ", arrayOfFractions[i].numerator, arrayOfFractions[i].denominator);
    }

    free(arrayOfFractions);
    return 0;
}
