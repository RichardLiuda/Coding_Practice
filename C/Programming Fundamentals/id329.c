#include <stdio.h>

int a[114];
int b[114];
int c[114];
int flag[11451];

int main()
{
    int n1, n2;
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++)
    {
        scanf("%d", &a[i]);
        flag[a[i]] = 1;
    }
    int cnt = 0;
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++)
    {
        scanf("%d", &b[i]);
        if (flag[b[i]])
            flag[b[i]] = 2;
    }
    int *p = c;
    for (int i = 0; i < n1; i++)
        if (flag[a[i]] != 2)
            *p++ = a[i];
    for (int i = 0; i < n2; i++)
        if (flag[b[i]] != 2)
            *p++ = b[i];
    if (p - c == 0)
        printf("NULL");
    else
    {
        for (int i = 0; i < p - c; i++)
            for (int j = 0; j < p - c - 1; j++)
                if (c[j] < c[j + 1])
                {
                    int temp = c[j];
                    c[j] = c[j + 1];
                    c[j + 1] = temp;
                }
        for (int i = 0; i < p - c; i++)
            printf("%d ", c[i]);
    }
    return 0;
}