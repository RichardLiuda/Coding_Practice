#include <stdio.h>

char *p, *s;
char *q;
char plt[1145], cit[1145];
char key[1145];

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        getchar();
        scanf("%s", &plt);
        scanf("%s", &key);
        p = plt;
        q = key;
        s = cit;
        while (*p != '\0')
        {
            if (*q == '\0')
                q = key;
            *s = *p + *q - '0';
            if ((*s < 'a' || *s > 'z') && (*s < 'A' || *s > 'Z'))
                *s -= 26;
            p++;
            q++;
            s++;
        }
        *(s++) = '\0';
        printf("%s\n", cit);
    }
    return 0;
}