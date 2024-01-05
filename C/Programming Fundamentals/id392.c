#include <stdio.h>

int mat[1145][1145];
int x[1145], y[1145];
int flag[1145];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    int t, a, b, x0, y0;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        flag[i] = 0;
        scanf("%d %d", &a, &b);
        for (int j = 0; j < a; j++)
        {
            for (int k = 0; k < b; k++)
            {
                int n;
                scanf("%d", &n);
                mat[j][k] = n;
            }
        }

        for (int j = 0; j < a; j++)
        {
            int max = 0;
            for (int k = 0; k < b; k++)
            {
                if (mat[j][k] > max)
                {
                    max = mat[j][k];
                    y0 = k;
                }
            }
            int min = 114514;
            for (int k = 0; k < a; k++)
            {
                if (mat[k][y0] < min)
                {
                    min = mat[k][y0];
                    x0 = k;
                }
            }
            if (min == max)
            {
                x[i] = x0;
                y[i] = y0;
                flag[i] = 1;
                continue;
            }
        }
    }
    for (int i = 0; i < t; i++)
    {
        if (flag[i])
            printf("%d %d\n", x[i], y[i]);
        else
            printf("-1\n");
    }
    return 0;
}