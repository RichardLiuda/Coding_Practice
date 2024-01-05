#include <stdio.h>
#include <string.h>

int main()
{
    int n;
    scanf("%d", &n);
    char ch1[n][1145];
    char ch2[n][1145];
    for (int i = 0; i < n; i++)
    {
        scanf("%s", &ch1[i]);
        scanf("%s", &ch2[i]);
        int len2 = strlen(ch2[i]);
        for (int j = 0; j < len2; j++)
        {
            ch1[i][j] = ch2[i][j];
        }
        if (ch1[i][len2 != '\0'])
            ch1[i][len2] = '\0';
    }
    for (int i = 0; i < n; i++)
    {
        printf("%s\n", ch1[i]);
    }
    return 0;
}