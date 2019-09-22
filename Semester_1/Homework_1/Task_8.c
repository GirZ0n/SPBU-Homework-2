#include <stdio.h>

long long recursiveFactorial(int n)
{
    if (n == 0)
    {
        return 1;
    }

    return n * recursiveFactorial(n - 1);
}

long long iterativeFactorial(int n)
{
    long long result = 1;
    for (int i = 1; i <= n; i++)
    {
        result *= i;
    }

    return result;
}

int main()
{
    int n = 0;
    printf("Enter N:");
    scanf("%d", &n);
    printf("N! = %lld (Recursive), %lld (Iterative)", recursiveFactorial(n), iterativeFactorial(n));
    return 0;
}