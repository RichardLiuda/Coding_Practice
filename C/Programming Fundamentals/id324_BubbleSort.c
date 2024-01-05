#include <stdio.h>

int cnt[11451];
void Bubblesort(int arr[][21], int n, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[cnt[n]][j] > arr[cnt[n]][j + 1])
            {
                int t = arr[cnt[n]][j];
                arr[cnt[n]][j] = arr[cnt[n]][j + 1];
                arr[cnt[n]][j + 1] = t;
            }
        }
        for (int j = 0; j < size; j++)
        {
            arr[cnt[n] + 1][j] = arr[cnt[n]][j];
        }
        cnt[n]++;
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    int ans[T][11451][21];
    int n[T];
    for (int i = 0; i < T; i++)
    {
        scanf("%d", &n[i]);
        for (int j = 0; j < n[i]; j++)
        {
            scanf("%d", &ans[i][0][j]);
        }
        Bubblesort(ans[i], i, n[i]);
    }
    for (int i = 0; i < T; i++)
    {
        for (int j = 0; j < cnt[i]; j++)
        {
            for (int k = 0; k < n[i]; k++)
            {
                printf("%d", ans[i][j][k]);
                printf(k == n[i] - 1 ? "\n" : " ");
            }
        }
    }
    return 0;
}