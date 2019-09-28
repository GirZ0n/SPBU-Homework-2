#include <stdio.h>

struct Fraction
{
    int numerator;
    int denominator;
};

struct Fraction createFraction(int numerator, int denominator)
{
    struct Fraction currentFraction;
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

struct Fraction getIrreducibleFraction(int numerator, int denominator)
{
    int greatestCommonDivisor = getGreatestCommonDivisor(numerator, denominator);

    return createFraction(numerator / greatestCommonDivisor, denominator / greatestCommonDivisor);
}


int main() {
    int inputDenominator = 0;
    printf("Enter the denominator:");
    scanf("%d", &inputDenominator);

    printf("All simple irreducible fractions in the interval (0, 1): ");
    struct Fraction currentIrreducibleFraction = createFraction(0, 0);
    for (int i = 1; i < inputDenominator; i++)
    {
        currentIrreducibleFraction = getIrreducibleFraction(i, inputDenominator);
        printf("%d/%d ; ", currentIrreducibleFraction.numerator, currentIrreducibleFraction.denominator);
    }

    return 0;
}
