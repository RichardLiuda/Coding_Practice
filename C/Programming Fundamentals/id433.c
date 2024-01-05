#include <stdio.h>
#include <string.h>

char word[11451][114];

struct stat
{
    char wd[114];
    int cnt;
} stats[11414];

int main()
{
    int i = 0;
    int j = 0;
    while (1)
    {
        scanf("%s", word[i]);
        if (word[i][0] == '0')
            break;
        int flag = 0;
        for (int k = 0; k < j; k++)
        {
            if (strcmp(word[i], stats[k].wd) == 0)
            {
                stats[k].cnt++;
                flag++;
                break;
            }
        }
        if (flag == 0)
        {
            strcpy(stats[j++].wd, word[i]);
            stats[j - 1].cnt++;
        }
        i++;
    }

    for (int k = 0; k < j; k++)
    {
        for (int l = k + 1; l < j; l++)
        {
            if (stats[k].cnt < stats[l].cnt)
            {
                struct stat temp = stats[k];
                stats[k] = stats[l];
                stats[l] = temp;
            }
        }
    }

    for (int k = 0; k < j; k++)
    {
        printf("%d %s\n", stats[k].cnt, stats[k].wd);
    }
    return 0;
}