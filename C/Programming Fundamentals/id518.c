#include <stdio.h>
#include <string.h>

char s[114][1145];
int t;
char longest[114][1145];
char temp[1145];
char temp_sum[1145];

void MaxLenWord(char s[])
{
    int len = 0, max_len = 0;
    for (int i = 0; i <= strlen(s); i++, len++)
    {
        if (s[i] == ' ' || s[i] == '\0')
        {
            if (len >= max_len)
            {
                if (len > max_len)
                {
                    memset(temp_sum, 0, sizeof(temp_sum));
                }
                max_len = len;
                temp[0] = ' ';
                for (int j = 0; j < len; j++)
                    temp[j + 1] = s[i - len + j];
                temp[len + 1] = '\0';
                strcat(temp_sum, temp);
            }
            len = -1;
        }
    }
    if (temp_sum[0] == ' ')
    {
        strcpy(temp_sum, temp_sum + 1);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    scanf("%d", &t);
    getchar();
    for (int i = 0; i < t; i++)
    {
        gets(s[i]);
        MaxLenWord(s[i]);
        strcpy(longest[i], temp_sum);
    }
    for (int i = 0; i < t; i++)
    {
        printf("%s\n", longest[i]);
    }
    return 0;
}