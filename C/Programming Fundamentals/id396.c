#include <stdio.h>
#include <string.h>

int max(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    char arr[1145];
    scanf("%s", arr);
    int n = strlen(arr);
    int f[n];
    for (int i = 0; i < n; i++)
        f[i] = 1;
    for (int i = 1; i < n; i++)
        for (int j = 0; j < i; j++)
            if (arr[i] >= arr[j])
                f[i] = max(f[j] + 1, f[i]);
    printf("%d", f[n - 1]);
    return 0;
}