#include <stdio.h>

typedef struct node
{
    int y, m, d;
    int flag;
} dat;
dat date;

void isLeap(dat *a)
{
    if (((*a).y % 4 == 0 && (*a).y % 100 != 0) || (*a).y % 400 == 0)
    {
        (*a).flag = 1;
    }
}

int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int calc(dat a)
{
    int sum = 0;
    for (int i = 0; i < a.m - 1; i++)
    {
        sum += days[i];
    }
    sum += a.d;
    sum += a.flag;
    return sum;
}

int main()
{
    scanf("%d%d%d", &date.y, &date.m, &date.d);
    isLeap(&date);
    printf("%d", calc(date));
    return 0;
}