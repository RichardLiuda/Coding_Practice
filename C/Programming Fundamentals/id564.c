#include <stdio.h>

int mark[1145];
int *p;

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &mark[i]);
        if (n % 2)
        {
            p = mark + (n - 1) / 2;
            p--;
            printf("%d ", *p);
            p++;
            p++;
            printf("%d\n", *p);
        }
        else
        {
            p = mark + n / 2 - 1;
            printf("%d ", *p);
            p++;
            p++;
            printf("%d\n", *p);
        }
        int m;
        scanf("%d", &m);
        p = mark + m - 1;
        printf("%d\n", *p);
    }
    return 0;
}