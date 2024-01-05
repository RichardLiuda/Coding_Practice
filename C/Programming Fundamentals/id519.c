#include <stdio.h>
#include <string.h>

int a[1145], b[1145];

int Divisor_sum(int n)
{
    int sum = 0;
    for (int i = 1; i < n; i++)
    {
        if (n % i == 0)
            sum += i;
    }
    return sum;
}

int isAffinity(int a, int b)
{
    if (a == b)
        return 0;
    else if (Divisor_sum(a) == b && Divisor_sum(b) == a)
        return 1;
    else
        return 0;
}

int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        scanf("%d %d", &a[i], &b[i]);
    }
    for (int i = 0; i < t; i++)
    {
        if (isAffinity(a[i], b[i]))
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}