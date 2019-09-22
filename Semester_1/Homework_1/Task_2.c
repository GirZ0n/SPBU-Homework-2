#include <stdio.h>

int main()
{
    int dividend = 0;
    int divisor = 0;
    printf("Enter the value of A:");
    scanf("%d", &dividend);
    printf("Enter the value of B:");
    scanf("%d", &divisor);

    int quotient = 0;
    while (dividend >= divisor)
    {
        quotient++;
        dividend -= divisor;
    }

    printf("A div B = %d", quotient);
    return 0;
}