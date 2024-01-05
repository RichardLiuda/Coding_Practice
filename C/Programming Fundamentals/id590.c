#include <stdio.h>

int n;

struct node
{
    int year;
    int month;
    int day;
};
struct node stu[114], temp;

int cmp(struct node a, struct node b)
{
    if (a.year != b.year)
        return a.year > b.year;
    else if (a.month != b.month)
        return a.month > b.month;
    else
        return a.day > b.day;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d %d", &stu[i].year, &stu[i].month, &stu[i].day);
    }
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
        {
            if (cmp(stu[j], stu[j + 1]))
            {
                temp = stu[j];
                stu[j] = stu[j + 1];
                stu[j + 1] = temp;
            }
        }
    printf("%d-%d-%d", stu[1].year, stu[1].month, stu[1].day);
    return 0;
}