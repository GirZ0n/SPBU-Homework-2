#include <stdio.h>
struct Fraction
{
    int numerator;
    int denominator;
};


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

    struct Fraction irreducibleFraction;
    irreducibleFraction.numerator = numerator / greatestCommonDivisor;
    irreducibleFraction.denominator = denominator / greatestCommonDivisor;

    return irreducibleFraction;
}


int main() {
    int inputDenominator = 0;
    printf("Enter the denominator:");
    scanf("%d", &inputDenominator);

    printf("All simple irreducible fractions in the interval (0, 1): ");
    struct Fraction currentIrreducibleFraction;
    currentIrreducibleFraction.numerator = 0;
    currentIrreducibleFraction.denominator = 0;
    for (int i = 0; i < inputDenominator - 1; i++)
    {
        currentIrreducibleFraction = getIrreducibleFraction(i + 1, inputDenominator);
        printf("%d/%d ; ", currentIrreducibleFraction.numerator, currentIrreducibleFraction.denominator);
    }

    return 0;
}
