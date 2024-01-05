#include <stdio.h>

char *p;
char s[1145];

int main()
{
    int t;
    scanf("%d", &t);
    getchar();
    while (t--)
    {
        scanf("%s", &s);
        p = s;
        int i = 0;
        while (*p != '\0')
        {
            i++;
            p++;
        }
        printf("%d\n", i);
    }
    return 0;
}