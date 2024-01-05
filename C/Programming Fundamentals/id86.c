#include <stdio.h>
#include <math.h>
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    char a;
    int m, n;
    scanf("%d %d %c", &m, &n, &a);
    switch (a)
    {
    case '+':
        printf("%d", m + n);
        break;
    case '-':
        printf("%d", m - n);
        break;
    case '*':
        printf("%d", m * n);
        break;
    case '/':
        switch (n)
        {
        case 0:
            printf("Divided by zero!");
            break;
        }
        break;
    default:
        printf("Invalid operator!");
        break;
    }
    return 0;
}