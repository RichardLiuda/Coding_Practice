#include <stdio.h>

long long muti(int n)
{
    if (n == 1)
        return 1;
    return n * muti(n - 1);
}

int prime(int n)
{
    if (n == 1)
        return 0;
    for (int i = 2; i <= n / 2; i++)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

int main()
{
    int t;
    int x;
    int n;
    int a, b;
    scanf("%d", &t);
    while (t--)
    {
        printf("1 计算n!\n2 输出素数\n3 判定闰年\n");
        scanf("%d", &x);
        switch (x)
        {
        case 1:
            scanf("%d", &n);
            printf("%lld", muti(n));
            break;
        case 2:
        {
            scanf("%d %d", &a, &b);
            for (int i = a; i <= b; i++)
            {
                if (prime(i))
                    printf("%d ", i);
            }
        }
        break;
        case 3:
            scanf("%d", &n);
            if ((n % 4 == 0 && n % 100) || n % 400 == 0)
                printf("%d是闰年", n);
            else
                printf("%d非闰年", n);
            break;
        default:
            printf("INPUT ERROR!");
            break;
        }
        printf("\n\n");
    }
    return 0;
}