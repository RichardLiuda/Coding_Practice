#include <stdio.h>

int gcd(int x, int y)
{
    return y == 0 ? x : gcd(y, x % y);
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d\n", gcd(a, b));
    }
    return 0;
}