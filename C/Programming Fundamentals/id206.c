#include <stdio.h>
#include <math.h>

int check(int a)
{
    if (a >= 10)
        return a %= 10;
    return a;
}

void swap(int x, int y)
{
    int temp = y;
    y = x;
    x = temp;
}

int main()
{
    int n;
    scanf("%d", &n);
    int s[n], t[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &s[i]);
        int a = s[i] / 1000;
        int b = (s[i] % 1000) / 100;
        int c = (s[i] % 100) / 10;
        int d = s[i] % 10;
        a += 5;
        a = check(a);
        b += 5;
        b = check(b);
        c += 5;
        c = check(c);
        d += 5;
        d = check(d);
        int temp;
        temp = a;
        a = d;
        d = temp;
        temp = c;
        c = b;
        b = temp;
        t[i] = a * 1000 + b * 100 + c * 10 + d;
    }
    for (int i = 0; i < n; i++)
    {
        printf("%04d\n", t[i]);
    }
    return 0;
}
