#include <stdio.h>

int *p;
int a[1145];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    int n;
    scanf("%d", &n);
    while (n--)
    {
        int m;
        scanf("%d", &m);
        for (int i = 0; i < m; i++)
            scanf("%d", &a[i]);
        p = a;
        printf("%d %d \n", *(p + m / 2 - 1), *(p + m / 2 + 1));
        for (int i = 0; i < 3; i++)
        {
            int k;
            scanf("%d", &k);
            printf("%d ", *(p + k - 1));
        }
        printf("\n");
    }
    return 0;
}