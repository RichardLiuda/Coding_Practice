#include <stdio.h>

int m, n;
int max = 0, min = 1e6;
int arr[1145];
int *p;

void rec(int *p)
{
    scanf("%d", p);
}

int main()
{
    p = arr;
    scanf("%d%d", &m, &n);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            rec(p + i * n + j);
            if (*(p + i * n + j) < min)
                min = *(p + i * n + j);
            if (*(p + i * n + j) > max)
                max = *(p + i * n + j);
        }
    }
    printf("%d\n%d", max, min);
    return 0;
}