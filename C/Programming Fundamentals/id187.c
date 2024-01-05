#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    int T;
    scanf("%d", &T);
    getchar();
    int ans[T];
    memset(ans, 0, sizeof(ans));
    for (int i = 0; i < T; i++)
    {
        char a;
        int sym = 0;
        int n[11451];
        int figure = 0;
        memset(n, 0, sizeof(n));
        while ((a = getchar()) != '\n')
        {
            if (a == '-')
            {
                sym++;
                continue;
            }
            if (a >= '0' && a <= '9')
            {
                n[figure] = a - '0';
            }
            if (a >= 'A' && a <= 'F')
            {
                n[figure] = a - 'A' + 10;
            }
            figure++;
        }
        for (int j = figure - 1; j >= 0; j--)
        {
            ans[i] += (int)n[j] * pow(16, figure - 1 - j);
        }
        if (sym)
            ans[i] *= -1;
    }
    for (int i = 0; i < T; i++)
    {
        printf("%d\n", ans[i]);
    }
    return 0;
}