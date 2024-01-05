#include <stdio.h>

char arr[1145];

int isNumber(char *arr)
{
    char *p = arr;
    int flag = 1;
    int num = 0;
    int i = 0;
    while (*p != '\0')
    {
        if (!(*p <= '9' && *p >= '0'))
        {
            flag = 0;
            break;
        }
        int temp = *p - '0';
        num *= 10;
        num += temp;
        i++;
        p++;
    }
    if (flag)
        return num;
    else
        return -1;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        getchar();
        scanf("%s", &arr);
        if (isNumber(arr) == 1)
            printf("%s\n", arr);
        else
            printf("%d\n", isNumber(arr));
    }
    return 0;
}