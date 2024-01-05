#include <stdio.h>

char str[1145];
char ch;

void del_char(char str[], char ch)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        while (str[i] == ch)
        {
            for (int j = i; str[j] != '\0'; j++)
            {
                str[j] = str[j + 1];
            }
        }
    }
    return;
}

int main()
{
    scanf("%c", &ch);
    getchar();
    gets(str);
    del_char(str, ch);
    puts(str);
    return 0;
}