#include <stdio.h>

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    char a;
    a = getchar();
    if ((a >= 'x' && a <= 'z') || (a >= 'X' && a <= 'Z'))
        a -= 26;
    printf("%c", a + 4);
    return 0;
}