#include <stdio.h>

struct coo
{
    int sx;
    int sy;
    int ex;
    int ey;
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    int t;
    scanf("%d", &t);
    int ans[114514];
    for (int i = 1; i <= t; i++)
    {
        struct coo a, b;
        scanf("%d %d %d %d", &a.sx, &a.sy, &a.ex, &a.ey);
        scanf("%d %d %d %d", &b.sx, &b.sy, &b.ex, &b.ey);
        if (((b.sx - a.sx) * (b.sx - a.ex) <= 0 && (b.sy - a.sy) * (b.sy - a.ey) <= 0) || ((b.ex - a.ex) * (b.ex - a.sx) <= 0 && (b.ey - a.ey) * (b.ey - a.sy) <= 0) || ((b.sx - a.sx) * (b.sx - a.ex) <= 0 && (b.ey - a.sy) * (b.ey - a.ey) <= 0) || ((b.ex - a.sx) * (b.ex - a.ex) <= 0 && (b.sy - a.sy) * (b.sy - a.ey) <= 0))
            ans[i] = 1;
        else if (((a.sx - b.sx) * (a.sx - b.ex) <= 0 && (a.sy - b.sy) * (a.sy - b.ey) <= 0) || ((a.ex - b.ex) * (a.ex - b.sx) <= 0 && (a.ey - b.ey) * (a.ey - b.sy) <= 0) || ((a.sx - b.sx) * (a.sx - b.ex) <= 0 && (a.ey - b.sy) * (a.ey - b.ey) <= 0) || ((a.ex - b.sx) * (a.ex - b.ex) <= 0 && (a.sy - b.sy) * (a.sy - b.ey) <= 0))
            ans[i] = 1;
        else
            ans[i] = 0;
    }
    for (int i = 1; i <= t; i++)
    {
        if (ans[i])
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
