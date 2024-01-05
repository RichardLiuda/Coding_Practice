#include <stdio.h>
#include <string.h>

char *c1, *c2;
char S[1145], T[1145];
int len;

int cmp(char *c1, char *c2)
{
    int s = 0, t = 0;
    for (int i = 0; i < len; i++)
    {
        if (*(c1 + i) > *(c2 + i))
            s++;
        if (*(c1 + i) < *(c2 + i))
            t++;
    }
    if (s > t)
        return 1;
    if (s < t)
        return -1;
    if (s == t)
        return 0;
}

int main()
{
    c1 = S;
    c2 = T;
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%s", S);
        scanf("%s", T);
        if (strlen(S) > strlen(T))
        {
            printf("1\n");
            break;
        }
        if (strlen(S) < strlen(T))
        {
            printf("-1\n");
            break;
        }
        len = strlen(S);
        printf("%d\n", cmp(c1, c2));
    }
    return 0;
}
