#include <stdio.h>

int main()
{
    int a, m, n;
    double sum;
    scanf("%d%d%d", &a, &m, &n);
    printf("%lf", a * m + (a / 2.0) * n);
    return 0;
}