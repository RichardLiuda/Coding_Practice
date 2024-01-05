#include <stdio.h>
#include <string.h>

struct node
{
    int num, l, w;
};

int cmp(struct node a, struct node b)
{
    if (a.num != b.num)
        return a.num > b.num;
    else if (a.l != b.l)
        return a.l > b.l;
    else
        return a.w > b.w;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        struct node rect[n];
        int flag[n];
        memset(flag, 0, sizeof(flag));
        for (int i = 0; i < n; i++)
        {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            if (b < c)
            {
                b = b + c;
                c = b - c;
                b = b - c;
            }
            if (i > 0 && (a == rect[i - 1].num && b == rect[i - 1].l && c == rect[i - 1].w))
                continue;
            rect[i].num = a;
            rect[i].l = b;
            rect[i].w = c;
            flag[i] = 1;
        }
        for (int i = 0; i < n - 1; i++)
            for (int j = 0; j < n - i - 1; j++)
            {
                if (flag[j] == 0 || flag[j + 1] == 0)
                    continue;
                if (cmp(rect[j], rect[j + 1]))
                {
                    struct node temp = rect[j];
                    rect[j] = rect[j + 1];
                    rect[j + 1] = temp;
                }
            }
        for (int i = 0; i < n; i++)
            if (flag[i])
                printf("%d %d %d\n", rect[i].num, rect[i].l, rect[i].w);
    }
    return 0;
}