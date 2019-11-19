#include <stdio.h>

int main()
{
    int number = 0;
    printf("What Fibanachi number do you need to calculate?\n");
    printf("N: ");
    scanf("%d", &number);
    int fibA = 0;
    int fibB = 1;
    if (number == 0)
    {
        printf("F(0) = 0");
    }
    else if (number == 1)
    {
        printf("F(1) = 1");
    }
    else
    {
        int temporary = 0;
        for (int i = 0; i < number - 1; i++)
        {
            temporary = fibB;
            fibB = fibA + fibB;
            fibA = temporary;
        }

        printf("F(%d) = %d", number, fibB);
    }
    return 0;
}