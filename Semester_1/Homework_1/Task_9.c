#include <stdio.h>

long long power(int base, int exponent)
{
    if (exponent == 0)
    {
        return 1;
    }

    if (exponent % 2 == 0)
    {
        long long result = power(base, exponent / 2);
        return result * result;
    }

    return power(base, exponent - 1) * base;
}

int main()
{
    int base = 0;
    int exponent = 0;
    printf("Enter base:");
    scanf("%d", &base);
    printf("Enter exponent:");
    scanf("%d", &exponent);
    printf("base^exponent = %lld", power(base, exponent));
    return 0;
}