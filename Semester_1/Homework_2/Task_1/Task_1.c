#include <stdio.h>
#include <stdlib.h>

void printCompositions(int needToAdd, int maxTerm, int *composition, int index)
{
    if (needToAdd < 0 || maxTerm < 0)
    {
        return;
    }

    if (needToAdd == 0)
    {
        for (int i = 0; i < index; i++)
        {
            if (i + 1 == index)
            {
                printf("%d; \n", composition[i]);
                return;
            }
            else
            {
                printf("%d + ", composition[i]);
            }
        }
    }

    for (int i = maxTerm; i > 0; i--)
    {
        composition[index] = i;
        printCompositions(needToAdd - i, i, composition,index + 1);
    }
}

int main() {
    int number = 0;
    printf("Enter the number:");
    scanf("%d", &number);

    printf("The compositions of %d are:\n", number);
    int *numberComposition = malloc(number * sizeof(int));
    printCompositions(number, number, numberComposition, 0);
    return 0;
}