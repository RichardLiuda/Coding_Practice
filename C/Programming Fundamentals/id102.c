#include <stdio.h>
#include <math.h>

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    int y,m,d;
    scanf("%d-%d-%d", &y, &m, &d);
    if(y%m==3||m%d==3) printf("YES");
    else printf("NO");
    return 0;
}