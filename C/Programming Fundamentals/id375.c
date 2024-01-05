#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int ma[n + 1][n + 1];
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            ma[i][j] = 0;
    ma[1][(1 + n) / 2] = 1;
    int c = (1 + n) / 2, r = 1;
    for (int i = 2; i <= n * n; i++)
    {
        if (r == 1 && c != n)
        {
            ma[n][c + 1] = i;
            r = n;
            c = c + 1;
            // printf("ma[%d][%d]=%d\n", r, c, ma[r][c]);
        }
        else if (r != 1 && c == n)
        {
            ma[r - 1][1] = i;
            r = r - 1;
            c = 1;
            // printf("ma[%d][%d]=%d\n", r, c, ma[r][c]);
        }
        else if (r == 1 && c == n)
        {
            ma[r + 1][c] = i;
            r = r + 1;
            // printf("ma[%d][%d]=%d\n", r, c, ma[r][c]);
        }
        else if (r != 1 && c != n)
        {
            if (ma[r - 1][c + 1] == 0)
            {
                ma[r - 1][c + 1] = i;
                r = r - 1;
                c = c + 1;
                // printf("ma[%d][%d]=%d\n", r, c, ma[r][c]);
            }
            else
            {
                ma[r + 1][c] = i;
                r = r + 1;
                // printf("ma[%d][%d]=%d\n", r, c, ma[r][c]);
            }
        }
        // printf("%d\n", i);
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            if (i == n)
            {
                if (j == n)
                {
                    printf("%d", ma[i][j]);
                }
                else
                {
                    printf("%d ", ma[i][j]);
                }
            }
            else
            {
                if (j == n)
                {
                    printf("%d\n", ma[i][j]);
                }
                else
                {
                    printf("%d ", ma[i][j]);
                }
            }
        }

    return 0;
}
