#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char str[3][114];

int main()
{
    int t;
    int cnt = 0;
    scanf("%d", &t);
    char *arr;
    while (t--)
    {
        int cnt = 0;
        getchar();
        arr = (char *)malloc(sizeof(char) * 114);
        int l, r;
        for (int i = 0; i < 3; i++)
            scanf("%s", &str[i]);
        for (int i = 0; i < 3; i++)
        {
            scanf("%d%d", &l, &r);
            for (int j = l - 1; j < r; j++)
            {
                *(arr + cnt) = *(str[i] + j);
                cnt++;
            }
        }
        printf("%s\n", arr);
    }
    return 0;
}