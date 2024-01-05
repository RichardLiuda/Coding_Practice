#include <stdio.h>

double rate[4] = {6.2619,
                  6.6744,
                  0.0516,
                  0.8065};
double *p = rate;

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        char c;
        scanf(" %c", &c);
        double a;
        scanf("%lf", &a);
        if (c == 'D')
            printf("%.4lf\n", a * (*p));
        else if (c == 'E')
            printf("%.4f\n", a * (*(p + 1)));
        else if (c == 'Y')
            printf("%.4f\n", a * (*(p + 2)));
        else if (c == 'H')
            printf("%.4f\n", a * (*(p + 3)));
    }
    return 0;
}