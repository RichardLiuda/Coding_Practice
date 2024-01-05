#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    printf("%lld\n", (long long)1e5 * n);
    long long sum = 0;
    long long temp;
    if (!n)
        printf("%lld", sum);
    else
    {
        sum = 2;
        for (int i = 1; i < n; i++)
        {
            sum *= 2;
        }
        sum--;
        printf("%lld", sum);
    }
    return 0;
}