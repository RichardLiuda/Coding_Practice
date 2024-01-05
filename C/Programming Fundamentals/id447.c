#include <stdio.h>
#include <string.h>

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    int t;
    scanf("%d", &t);
    char str[t][100];
    char ch;
    for (int i = 0; i < t; i++)
    {
        int k = 1;
        scanf("%s", str[i]);
        // while ((ch = getchar()) != '\n')
        // {
        //     str[i][k++] = ch;
        // }
        // str[i][k] = '\0';
        for (int j = 0; j < strlen(str[i]); j++)
        {
            if (str[i][j] <= 'z' && str[i][j] >= 'a')
            {
                str[i][j] -= 32;
            }
            else if (str[i][j] <= 'Z' && str[i][j] >= 'A')
            {
                str[i][j] += 32;
            }
        }
    }
    for (int i = 0; i < t; i++)
    {
        int k = 0;
        while (str[i][k] != '\0')
            printf("%c", str[i][k++]);
        printf("\n");
    }
    return 0;
}