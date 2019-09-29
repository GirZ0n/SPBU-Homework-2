#include <stdio.h>
#include <stdlib.h>

void printCompositions(int boo, int maxTerm, int *composition, int index)
{
    return;
}

int main() {
    int number = 0;
    printf("Enter the number:");
    scanf("%d", &number);

    printf("The compositions of %d are:\n", number);
    int *numberComposition = malloc(number * sizeof(int));
    printCompositions(number, number, &numberComposition, 0);
    return 0;
}