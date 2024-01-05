#include <stdio.h>
#include <string.h>

char *p;
char s[1145];

char *substr(char *s, int startloc, int len)
{
    if (startloc > strlen(s))
    {
        return 0x0;
    }
    p = s + startloc - 1;
    while (len--)
    {
        if (*p == '\0')
            break;
        printf("%c", *p);
        p++;
    }
    printf("\n");
    return p;
}

int main()
{
    int t;
    scanf("%d", &t);
    getchar();
    while (t--)
    {
        int l, len;
        scanf("%s", &s);
        scanf("%d %d", &l, &len);
        if (!substr(s, l, len))
            printf("NULL\n");
        // if (l > strlen(s))
        // {
        //     printf("NULL\n");
        //     continue;
        // }
        // p = s + l - 1;
        // while (len--)
        // {
        //     if (*p == '\0')
        //         break;
        //     printf("%c", *p);
        //     p++;
        // }
        // printf("\n");
    }
    return 0;
}