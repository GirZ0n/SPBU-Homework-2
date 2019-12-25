#include <string.h>
#include "stackOfDouble.h"
#include "stringAndCharOparations.h"

double getResultOfOperation(double valueA, double valueB, char operator)
{
    switch (operator)
    {
        case '+':
        {
            return valueA + valueB;
        }
        case '-':
        {
            return valueA - valueB;
        }
        case '*':
        {
            return valueA * valueB;
        }
        case '/':
        {
            return valueA / valueB;
        }
        default:
        {
            return 0;
        }
    }
}

void operatorProcessingInCalculatePostfixNotation(char* postfixNotation, int index, StackOfDouble* stack)
{
    double operandB = popDouble(stack);
    double operandA = popDouble(stack);
    double result = getResultOfOperation(operandA, operandB, postfixNotation[index]);
    pushDouble(result, stack);
}

double calculatePostfixNotation(char* postfixNotation)
{
    struct StackOfDouble* stack = createStackOfDouble();
    int inputStringLength = (int) strlen(postfixNotation);
    for (int i = 0; i < inputStringLength; i++)
    {
        if (isOperator(postfixNotation, i))
        {
            operatorProcessingInCalculatePostfixNotation(postfixNotation, i, stack);
        }
        else if (isUnaryNegative(postfixNotation, i) || isDigit(postfixNotation[i]))
        {
            pushDouble(getNumberAsDouble(postfixNotation, &i), stack);
        }
        else
        {
            continue;
        }
    }

    double result = popDouble(stack);
    deleteStackOfDouble(stack);
    return result;
}