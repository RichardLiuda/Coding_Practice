#include <stdio.h>
#include <math.h>

int ans[114514][1145];
int len[1919];
int flag[1919];

void find(int x, int n)
{
    int k = 1;
    for (int i = 1; i < n; i++)
    {
        if (n % i == 0)
        {
            ans[x][k] = i;
            k++;
        }
    }
    len[x] = k - 1;
    int sum = 0;
    for (int p = 1; p <= len[x]; p++)
    {
        sum += ans[x][p];
    }
    if (sum == n)
        flag[x] = 1;
    else
        flag[x] = 0;
}

void print(int n)
{
    for (int j = 1; j <= n; j++)
    {
        if (flag[j])
            printf("yes,");
        else
            printf("no,");
        for (int i = 1; i <= len[j]; i++)
        {
            if (i == len[j])
            {
                printf("%d", ans[j][i]);
                break;
            }
            printf("%d,", ans[j][i]);
        }
        printf("\n");
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int a;
        scanf("%d", &a);
        find(i, a);
    }
    print(n);

    return 0;
}
