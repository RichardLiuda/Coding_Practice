#include <stdio.h>
#include <math.h>

// double tem;

int main()
{
    double a[1145];
    int day = 0;
    double sum = 0;
    double delta = 1.0e-3;
    double *p = a;
    while (1)
    {
        scanf("%lf", &a[day]);
        if (*(p + day) < delta)
            break;
        sum += *(p + day);
        day++;
    }
    printf("%d %g", day, sum / day);
    return 0;
}