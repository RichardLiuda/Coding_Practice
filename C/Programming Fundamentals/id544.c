#include <stdio.h>

char arr[1145];

void inver(char arr[], int n)
{
    if (n == 1)
    {
        printf("%c", arr[n - 1]);
        return;
    }
    printf("%c", arr[n - 1]);
    inver(arr, n - 1);
}

int main()
{
    int n;
    scanf("%d", &n);
    getchar();
    gets(arr);
    inver(arr, n);
    return 0;
}