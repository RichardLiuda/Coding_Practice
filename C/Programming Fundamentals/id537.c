#include <stdio.h>

long long ans;
// R=0,P=1,G=2
void RPG(int n, int c)
{
    if (n == 1)
    {
        if (!c)
            return;
        else
        {
            ans++;
            return;
        }
    }
    for (int i = 1; i <= 2; i++)
    {
        RPG(n - 1, (c + i) % 3);
    }
    return;
}

int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        ans = 0;
        if (n == 1)
            printf("3\n");
        else
        {
            RPG(n, 0);
            printf("%lld\n", 3 * ans);
        }
    }
    return 0;
}