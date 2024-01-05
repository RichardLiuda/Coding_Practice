#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int flag = 1;
    for (int i = 2; i * 2 <= n; i++)
    {
        if ((2 * n) % i)
            continue;
        int j = 2 * n / i;
        if ((j / 2) % 2)
        { // j为奇
            if (j % 2)
                continue;
            j /= 2;
            if (i < (j + 1) / 2)
                continue;
            int cnt = 0;
            flag = 0;
            for (int k = i - (j - 1) / 2; cnt < j; k++, cnt++)
                if (cnt == j - 1)
                    printf("%d\n", k);
                else
                    printf("%d ", k);
            // printf(cnt == j - 1 ? "%d\n", k : "%d ", k);
        }
        else
        { // j为偶
            j /= 2;
            if (i < j / 2)
                continue;
            if (n / (j / 2) % 2 == 0)
                continue;
            int cnt = 0;
            flag = 0;
            for (int k = n / j - j / 2 + 1; cnt < j; k++, cnt++)
                if (cnt == j - 1)
                    printf("%d\n", k);
                else
                    printf("%d ", k);
            // printf(cnt == j - 1 ? "%d\n", k : "%d ", k);
        }
    }
    if (flag)
        printf("NULL");
    return 0;
}