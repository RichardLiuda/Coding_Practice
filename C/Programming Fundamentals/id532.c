#include <stdio.h>
#include <string.h>

char str[1145][1145];

int isPalindrome(char s[])
{
    int len = strlen(s);
    for (int i = 0; i < len / 2; i++)
    {
        if (s[i] != s[len - i - 1])
            return 0;
    }
    return 1;
}

int main()
{
    int t;
    scanf("%d", &t);
    getchar();
    for (int i = 0; i < t; i++)
    {
        gets(str[i]);
    }
    for (int i = 0; i < t; i++)
    {
        if (isPalindrome(str[i]))
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}