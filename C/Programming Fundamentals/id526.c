#include <stdio.h>

int flag[1145];
int n;
int arr[1145];

int Judge(int arr[], int n)
{
    int step;
    if (n == 1)
        return 1;
    if (arr[1] - arr[0] > 0)
        step = 1;
    else if (arr[1] - arr[0] == 0)
        step = 2;
    else
        step = 3;
    for (int i = 2; i < n; i++)
    {
        if (arr[i] - arr[i - 1] > 0 && step > 1)
            return 0;
        if (arr[i] - arr[i - 1] == 0)
        {
            if (step == 1)
                step = 2;
            if (step == 3)
                return 0;
        }
        if (arr[i] - arr[i - 1] < 0)
        {
            if (step < 3)
                step = 3;
        }
    }
    return 1;
}

int main()
{
    while (scanf("%d", &n) != EOF)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }
        if (Judge(arr, n))
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}