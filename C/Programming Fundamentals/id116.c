#include <stdio.h>

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    int a, temp;
    scanf("%d", &a);
    if (a < 100000)
        printf("%d", a / 10);
    else if (a > 100000 && a <= 200000)
        printf("%d", 10000 + 0.075 * (a - 100000));
    else if (a > 200000 && a <= 400000)
        printf("%d", 17500 + 0.05 * (a - 200000));
    else if (a > 400000 && a <= 600000)
        printf("%d", 25000 + 0.03 * (a - 400000));
    else if (a > 600000 && a <= 1000000)
        printf("%d", 35000 + 0.015 * (a - 600000));
    else
        printf("%d", 10000 + 0.075 * 100000 + 0.05 * 200000 + 0.03 * 200000 + 0.015 * 400000 + 0.005 * (a - 1000000));
    return 0;
}