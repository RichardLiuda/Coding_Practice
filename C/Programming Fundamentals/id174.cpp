#include <bits/stdc++.h>
using namespace std;

bool cmp(int a, int b)
{
    return a > b;
}

int Short(int a[], int n, int len)
{
    int arr[n];
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        arr[i] = a[i];
        if (arr[i] > (len - arr[i]))
        {
            arr[i] = len - arr[i];
        }
    }
    sort(arr, arr + n, cmp);
    return arr[0];
}

// int Long(int arr[], int n, int len)
// {
//     int a[n];
//     int ans = 0;
//     for (int i = 0; i < n; i++)
//     {
//         a[i] = arr[i];
//     }
//     sort(a, a + n);
//     for (int i = 1; i < n; i++)
//     {
//         int del = (a[n - i] - a[n - i - 1]);
//         ans += del;
//     }
//     if (a[0] > a[n - 1])
//         ans += a[0];
//     else
//         ans += (len - a[n - 1]);
//     return ans;
// }

int main()
{
    int len, n;
    while (scanf("%d", &len) != EOF)
    {
        scanf("%d", &n);
        int a[n];
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
        }
        printf("%d ", Short(a, n, len));
        sort(a, a + n);
        printf("%d\n", max(len - a[0], a[n - 1]));
    }

    return 0;
}