#include <stdio.h>
#include <stdbool.h>

void sieveOfEratosthenes(bool isPrime[], int n)
{
    for (int i = 2; i * i <= n; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= n; j+= i)
            {
                isPrime[j] = true;
            }
        }
    }
}

int main()
{
    int n = 0;
    printf("Enter the value of N:");
    scanf("%d", &n);

    bool isPrime[n + 1];
    for (int i = 0; i <= n; i++)
    {
        isPrime[i] = true;
    }

    sieveOfEratosthenes(isPrime, n);

    printf("Prime numbers <= N: ");
    for (int i = 2; i <= n; i++)
    {
        if (isPrime[i])
        {
            printf("%d ", i);
        }
    }

    return 0;
}