#include <stdio.h>
#include <math.h>
int main()
{
    double eps = 1e-8;
    double dis;
    double t1, t2;
    scanf("%lf", &dis);
    t1 = dis / 1.2;
    t2 = dis / 3.0 + 50;
    if (fabs(t1 - t2) < eps)
        printf("All");
    else if (t1 < t2)
        printf("Walk");
    else
        printf("Bike");
    return 0;
}