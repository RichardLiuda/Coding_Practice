#include <stdio.h>

char a[21], b[21];
char *p1, *p2;

int main()
{
    scanf("%s", &a);
    scanf("%s", &b);
    p1 = a;
    p2 = b;
    int cnt = 0;
    while (*p1 != '\0')
    {
        if (*p1 == *p2)
        {
            p2++;
        }
        if (*p2 == '\0')
        {
            cnt++;
            p2 = b;
        }
        p1++;
    }
    printf("%d", cnt);
    return 0;
}