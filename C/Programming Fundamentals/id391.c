#include <stdio.h>

int mat[114][114];
int ans[114][114][114];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    int t, a[1145], b[1145];
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        scanf("%d %d", &a[i], &b[i]);
        for (int j = 0; j < a[i]; j++)
        {
            for (int k = 0; k < b[i]; k++)
            {
                int n;
                scanf("%d", &n);
                mat[j][k] = n;
            }
        }
        for (int j = 0; j < a[i]; j++)
        {
            for (int k = 0; k < b[i]; k++)
            {
                ans[i][k][j] = mat[j][k];
            }
        }
    }
    for (int i = 0; i < t; i++)
    {
        for (int j = 0; j < b[i]; j++)
        {
            for (int k = 0; k < a[i]; k++)
            {
                if (k != a[i] - 1)
                    printf("%d ", ans[i][j][k]);
                else
                    printf("%d\n", ans[i][j][k]);
            }
        }
    }
    return 0;
}