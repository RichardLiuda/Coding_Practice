#include <stdio.h>

int ma[6];
int *p;

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        p = ma;
        scanf("%d", p++);
        scanf("%d", p++);
        scanf("%d", p++);
        scanf("%d", p++);
        scanf("%d", p++);
        scanf("%d", p++);
        p = ma + 2;
        printf("%d ", *p);
        p += 3;
        printf("%d ", *p);
        printf("\n");
        p -= 4;
        printf("%d ", *p);
        p += 3;
        printf("%d ", *p);
        printf("\n");
        p -= 4;
        printf("%d ", *p);
        p += 3;
        printf("%d ", *p);
        printf("\n");
    }
    return 0;
}

