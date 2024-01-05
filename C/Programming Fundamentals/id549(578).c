#include <stdio.h>
#include <string.h>

int n;
struct node
{
    char num[114];
    char ans1[114];
    char ans2[114];
    char ans3[114];
    // node(int _num,char *_ans1,char *_ans2,char *_ans3){
    //     _num=num;
    //     _ans1=ans1;
    //     _ans2=ans2;
    //     _ans3=ans3;
    // }
} ans[114];
struct node *p = ans;

int cmp(struct node *a, struct node *b)
{
    char *p1 = (*a).ans1;
    char *p2 = (*b).ans1;
    int temp = 0;
    int t = 0;
    while (*p1 != '\0')
    {
        if (*p1 == *p2)
            temp++;
        p1++;
        p2++;
    }
    if (temp >= 0.9 * strlen((*a).ans1))
        t = 1;
    temp = 0;
    p1 = (*a).ans2;
    p2 = (*b).ans2;
    while (*p1 != '\0')
    {
        if (*p1 == *p2)
            temp++;
        p1++;
        p2++;
    }
    if (temp >= 0.9 * strlen((*a).ans2))
        t = 2;
    temp = 0;
    p1 = (*a).ans3;
    p2 = (*b).ans3;
    while (*p1 != '\0')
    {
        if (*p1 == *p2)
            temp++;
        p1++;
        p2++;
    }
    if (temp >= 0.9 * strlen((*a).ans3))
        t = 3;
    return t;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", &p[i].num);
        scanf("%s", &p[i].ans1);
        scanf("%s", &p[i].ans2);
        scanf("%s", &p[i].ans3);
    }
    int a = cmp(p + 1, p + 4);
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (cmp(p + i, p + j) == 1)
                printf("%s %s 1\n", p[i].num, p[j].num);
            else if (cmp(p + i, p + j) == 2)
                printf("%s %s 2\n", p[i].num, p[j].num);
            else if (cmp(p + i, p + j) == 3)
                printf("%s %s 3\n", p[i].num, p[j].num);
        }
    }
    return 0;
}