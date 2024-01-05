#include <stdio.h>
#include <string.h>

char chain[1145];
int cnt;

int isP(char *str, int b, int e, int cnt)
{
    if (b >= e)
        return cnt;
    return str[b] == str[e] ? isP(str, b + 1, e - 1, ++cnt) : 0;
}

int main()
{
    int t;
    scanf("%d", &t);
    getchar();
    while (t--)
    {
        scanf("%s", &chain);
        if (strlen(chain) % 2)
        {
            printf("%d\n", strlen(chain));
            continue;
        }
        cnt = 0;
        int ans;
        int flag = 0;
        while (isP(chain, 0, strlen(chain) - 1, cnt))
        {
            flag = 1;
            ans = isP(chain, 0, strlen(chain) - 1, cnt);
            cnt = 0;
            chain[strlen(chain) / 2] = '\0';
        }
        if (flag)
            printf("%d\n", ans);
        else
            printf("%d\n", strlen(chain));
    }
}