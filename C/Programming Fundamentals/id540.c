#include <stdio.h>

int p[1145], q[1145];
int a, n, m, x;

// void car(int k){
//     if(k==1) {f[k]=a;return;}
//     if(k==2) {f[k]=a;return;}
//     car(k-1);
//     p[k]=q[k-1]+q[k-2];
//     q[k]=p[k-1];
//     f[k]=f[k-1]+p[k-1]-q[k-1];
// }

int fib1(int t)
{
    if (t == 0)
        return 0;
    if (t == 1 || t == 2)
        return 1;
    if (t == 3)
        return 2;
    return fib1(t - 1) + fib1(t - 2) - 1;
}

int fib2(int t)
{
    if (t == 0)
        return 0;
    if (t == 1 || t == 2)
        return 0;
    if (t == 3)
        return 0;
    return fib2(t - 1) + fib2(t - 2) + 1;
}

int main()
{
    scanf("%d%d%d%d", &a, &n, &m, &x);
    int b = (m - a * fib1(n - 1)) / fib2(n - 1);
    printf("%d", a * fib1(x) + b * fib2(x));
    return 0;
}