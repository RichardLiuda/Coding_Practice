#include <stdio.h>
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    char a[100], c, min1, min2, max;
    int i = 0, k, n = 0;
    while ((c = getchar()) != EOF)
    /********** Write your code here! **********/
    {
        a[i++] = c;
    }
    a[i] = '\0';

    char temp;
    int cnt = 0;
    for (k = 0; k < i; k++)
    {
        temp = a[k];
        for (int j = k + 1; j < i; j++)
        {
            while (a[j] == temp)
            {
                for (int l = j; l < i; l++)
                {
                    a[l] = a[l + 1];
                }
                if (a[j] == '\0')
                    break;
            }
        }
    }
    int p = 0;
    do
    {
        p++;
    } while (a[p] != '\0');

    for (int u = 1; u < p; u++)
    {
        for (int j = 0; j < p - u; j++)
        {
            if (a[j] > a[j + 1])
            {
                char temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    printf("%s", a);
    /*******************************************/
    printf("\n");
    return 0;
}