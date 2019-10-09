#include <stdio.h>
#include <stdlib.h>

int min(int numberA, int numberB)
{
    return (numberA < numberB ? numberA : numberB);
}

void printCompositions(int needToAdd, int *composition, int numberOfTerms)
{
    if (needToAdd == 0)
    {
        for (int i = 0; i < numberOfTerms; i++)
        {
            printf("%d", composition[i]);
            printf("%s", (i + 1 == numberOfTerms ? ";\n" : " + "));
        }

        return;
    }

    int maxTerm = 0;
    if (numberOfTerms > 0)
    {
        maxTerm = min(needToAdd, composition[numberOfTerms - 1]);
    }
    else
    {
        maxTerm = needToAdd;
    }

    for (int term = maxTerm; term > 0; term--)
    {
        composition[numberOfTerms] = term;
        printCompositions(needToAdd - term, composition, numberOfTerms + 1);
    }
}

int main() {
    int number = 0;
    printf("Enter the number:");
    scanf("%d", &number);

    printf("The compositions of %d are:\n", number);
    int *numberComposition = malloc(number * sizeof(int));
    printCompositions(number, numberComposition, 0);
    
    free(numberComposition);
    return 0;
}
