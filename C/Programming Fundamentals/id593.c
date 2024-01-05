#include <stdio.h>

int main()
{
    int t;
    char ch[t];
    scanf("%d", &t);
    int n[t];
    for (int i = 0; i < t; i++)
    {
        scanf("%d %c", &n[i], &ch[i]);
    }
    for (int i = 0; i < t; i++)
    {
        for (int j = 1; j <= n[i]; j++)
        {
            for (int k = 2 * n[i] - 1; k >= 0; k--)
                printf(k - (2 * j - 1) > 0 ? " " : !k ? "\n"
                                                      : "%c",
                       ch[i]);
        }
        printf("\n");
    }
    return 0;
}