#include <stdio.h>

typedef struct
{
    int num;
    char name[20];
    double m1, m2, m3;
    double ave;
} stu;

int main()
{
    int n;
    scanf("%d", &n);
    stu s[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &s[i].num);
        scanf("%s", s[i].name);
        scanf("%lf%lf%lf", &s[i].m1, &s[i].m2, &s[i].m3);
        s[i].ave = (s[i].m1 + s[i].m2 + s[i].m3) / 3.0;
        printf("%d %s %.2lf %.2lf %.2lf %.2lf\n", s[i].num, s[i].name, s[i].m1, s[i].m2, s[i].m3, s[i].ave);
    }
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - 1 - i; j++)
            if (s[j].ave < s[j + 1].ave)
            {
                stu temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
    printf("%s %.2lf", s[0].name, s[0].ave);
    return 0;
}