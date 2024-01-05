#include <stdio.h>
#include <math.h>
#include <stdlib.h>
double e = 0.001;
int f(double a, double b)
{
    if (fabs(a - b) < e)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    int a;
    int arr[11];
    for (int i = 0; i < 9; i++)
    {
        scanf("%d ", &arr[i]);
    }
    scanf("%d", &arr[9]);
    getchar();
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10 - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
    for (int i = 0; i < 10; i++)
    {
        printf("%d\n", arr[i]);
    }

    return 0;
}
