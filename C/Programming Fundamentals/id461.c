#include <stdio.h>
#include <string.h>

char str1[1145][11451];
int index[1145];
char str2[1145][11451];

int Substring(char str1[], char str2[], int index)
{
    int len = strlen(str1);
    if (index >= len || index < 0)
    {
        return 0;
    }
    for (int i = index; i < len; i++)
    {
        str2[i - index] = str1[i];
    }
    str2[len - index] = '\0';
    return 1;
}

int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        getchar();
        gets(str1[i]);
        scanf("%d", &index[i]);
    }
    for (int i = 0; i < t; i++)
    {

        if (Substring(str1[i], str2[i], index[i]))
            printf("%s\n", str2[i]);
        else
            printf("IndexError\n");
    }
    return 0;
}