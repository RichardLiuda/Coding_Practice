#include <stdio.h>

char str[1145];
void print(int n)
{
    static int i = 0;
    if (n == 1)
        return;
    print(n - 1);
    printf("%c", str[]);
    return;
}

int main()
{
    int n;
    scanf("%d", &n);
    getchar();
    gets(str);
    print(n);
    return 0;
}