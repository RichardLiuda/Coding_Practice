#include <stdio.h>
#include <math.h>

double e = 1e-3;

int main()
{

    double a[4];
    int ans;
    double A;
    double s;
    for (int j = 1; j <= 3; j++)
        scanf("%lf", &a[j]);
    s = (a[1] + a[2] + a[3]) / 2;
    if (a[1] < 0 || a[2] < 0 || a[3] < 0 || (s * (s - a[1]) * (s - a[2]) * (s - a[3]) < 0 || fabs(s * (s - a[1]) * (s - a[2]) * (s - a[3])) < e))
    {
        ans = 6;
    }
    else if (fabs(a[1] * a[1] - a[2] * a[2] - a[3] * a[3]) < e || fabs(a[2] * a[2] - a[1] * a[1] - a[3] * a[3]) < e || fabs(a[3] * a[3] - a[1] * a[1] - a[2] * a[2]) < e)
    {
        if (fabs(a[1] - a[2]) < e || fabs(a[1] - a[3]) < e || fabs(a[2] - a[3]) < e)
        {
            ans = 3;
            A = sqrt(s * (s - a[1]) * (s - a[2]) * (s - a[3]));
        }
        else
        {
            ans = 2;
            A = sqrt(s * (s - a[1]) * (s - a[2]) * (s - a[3]));
        }
    }
    else if (fabs(a[1] - a[2]) < e || fabs(a[2] - a[3]) < e || fabs(a[1] - a[3]) < e)
    {
        if (fabs(a[1] - a[2]) < e && fabs(a[2] - a[3]) < e)
        {
            ans = 4;
            A = sqrt(s * (s - a[1]) * (s - a[2]) * (s - a[3]));
        }
        else
        {
            ans = 1;
            A = sqrt(s * (s - a[1]) * (s - a[2]) * (s - a[3]));
        }
    }
    else
    {
        ans = 5;
        A = sqrt(s * (s - a[1]) * (s - a[2]) * (s - a[3]));
    }

    switch (ans)
    {
    case 1:
        printf("等腰三角形");
        break;
    case 2:
        printf("直角三角形");
        break;
    case 3:
        printf("等腰直角三角形");
        break;
    case 4:
        printf("等边三角形");
        break;
    case 5:
        printf("普通三角形");
        break;
    case 6:
        printf("非三角形");
        break;
    }
    return 0;
}
