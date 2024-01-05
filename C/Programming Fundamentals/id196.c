#include <stdio.h>

int prime(int m)
{
    for (int i = 2; i <= m / 2; i++)
    {
        if (m % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int pal(int m)
{
    int temp = m, len = 0;
    while (temp)
    {
        temp /= 10;
        len++;
    }
    int num[len];
    for (int i = 0; i < len; i++)
    {
        num[i] = m % 10;
        m /= 10;
    }
    for (int i = 0; i < len / 2; i++)
    {
        if (num[i] != num[len - i - 1])
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    int n;
    scanf("%d", &n);
    float a[n], b[n];
    for (int i = 1; i <= n; i++)
    {
        scanf("%f %f", &a[i], &b[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        if (b[i] < 0 || a[i] > b[i])
        {
            printf("Not found\n");
            continue;
        }
        int ans = 0;
        for (int j = (int)a[i]; j <= (int)b[i]; j++)
        {
            if (j <= 1)
            {
                continue;
            }
            if (prime(j) && pal(j))
            {
                printf("%d\n", j);
                ans++;
            }
        }
        if (ans == 0)
        {
            printf("Not found\n");
        }
    }
    return 0;
}
