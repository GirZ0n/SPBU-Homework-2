#include <stdio.h>

int main ()
{
    int x = 0;
    printf("Enter the value of X:");
    scanf("%d", &x);
    long long xSquared = x * x;
    long long result = (xSquared + 1) * (xSquared + x) + 1;
    printf("Result: %lld", result);
    return 0;
}