#include <stdio.h>

int isprime(int n)
{
    if (n == 2 || n == 3)
        return 1;
    if (n == 1)
        return 0;
    for (int i = 2; i <= n / 2; i++)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

int main()
{
    int m, n, sum = 0;
    scanf("%d%d", &m, &n);
    for (int i = m; i <= n; i++)
    {
        if (isprime(i))
        {
            sum += i;
        }
    }
    printf("%d", sum);
    return 0;
}