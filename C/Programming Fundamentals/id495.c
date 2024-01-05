#include <stdio.h>

int let = 0, num = 0, spa = 0, oth = 0;
char str[1145];

int main()
{
    gets(str);
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ' ')
            spa++;
        else if (str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'A' && str[i] <= 'Z')
            let++;
        else if (str[i] >= '0' && str[i] <= '9')
            num++;
        else
            oth++;
    }
    printf("%d %d %d %d", let, num, spa, oth);
    return 0;
}