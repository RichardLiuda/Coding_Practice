#include <stdio.h>

int f[114];

int fib(int n)
{
    if (n <= 2)
        return f[n];
    return fib(n - 1) + fib(n - 2);
}

int main()
{
    f[0] = 0;
    f[1] = 1;
    f[2] = 1;
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int k;
        scanf("%d", &k);
        printf("%d\n", fib(k));
    }
    return 0;
}