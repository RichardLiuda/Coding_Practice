#include <stdio.h>
#include <math.h>

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    double a, b, c;
    scanf("%lf %lf %lf", &a, &b, &c);
    if (a == 0)
    {
        printf("x1=%.3lf x2=%.3lf", -c / b, -c / b);
    }
    else
    {
        if (b * b - 4 * a * c < 0)
        {
            double m = -b / (2.0 * a);
            double n = sqrt(-b * b + 4 * a * c) / (2.0 * a);
            printf("x1=%.3lf+%.3lfi x2=%.3lf-%.3lfi", m, n, m, n);
        }
        else
        {

            double x1, x2;
            x1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
            x2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
            printf("x1=%lf x2=%lf", x1, x2);
        }
    }
    return 0;
}