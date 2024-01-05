#include <stdio.h>
#include <math.h>

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    int a;
    scanf("%d", &a);
    int t = 3;
    int b = a;
    int c = a;
    if (a < 100 || a >= 1000)
    {
        printf("ERROR");
        return 0;
    }
    while (t--)
    {
        c = a % 10;
        a /= 10;
        b -= c * c * c;
    }
    if (b == 0)
        printf("1");
    else
        printf("0");
    return 0;
}