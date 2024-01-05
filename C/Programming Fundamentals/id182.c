#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int prime(int n)
{
    int temp = sqrt(n);
    if (n == 1)
        return 0;
    for (int i = 2; i <= temp; i++)
        if (n % i == 0)
            return 0;
    return 1;
}

int figure(int n)
{
    int temp = 0;
    while (n)
    {
        n /= 10;
        temp++;
    }
    return temp;
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
    int n;
    scanf("%d", &n);
    int ans[n];
    for (int i = 0; i < n; i++)
    {
        int a;
        scanf("%d", &a);
        if (prime(a) && figure(a) <= 5 && pal(a))
            ans[i] = 1;
        else
            ans[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        if (ans[i])
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}