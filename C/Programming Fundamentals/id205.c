#include <stdio.h>
#include <math.h>

int main()
{
    int t;
    scanf("%d", &t);
    int ans[t];
    for (int i = 1; i <= t; i++)
    {
        int n, k;
        scanf("%d %d", &n, &k);
        ans[i] = 0;
        int temp;
        for (int j = 1; j <= k; j++)
        {
            temp = 1;
            for (int h = 1; h <= j; h++)
            {
                temp = temp * n;
            }
            ans[i] += temp;
        }
    }
    for (int i = 1; i <= t; i++)
    {
        printf("%d\n", ans[i]);
    }
    return 0;
}
