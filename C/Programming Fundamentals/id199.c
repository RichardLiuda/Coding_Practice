#include <stdio.h>
#include <math.h>

int main()
{
    int a, n;
    int ans = 0;
    scanf("%d%d", &a, &n);
    for (int i = 1; i <= n; i++)
    {
        int temp = i - 1;
        int sum = a;
        while (temp--)
        {
            sum = 10 * sum + a;
        }
        ans += sum;
    }
    printf("%d", ans);
    return 0;
}
