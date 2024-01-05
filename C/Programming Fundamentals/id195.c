#include <stdio.h>
#include <math.h>

double e = 1e-3;

int main()
{
    int n;
    scanf("%d", &n);
    double a[4];
    int ans[n + 1];
    double A[n + 1];
    double s;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 3; j++)
            scanf("%lf", &a[j]);
        s = (a[1] + a[2] + a[3]) / 2;
        if (a[1] < 0 || a[2] < 0 || a[3] < 0 || (s * (s - a[1]) * (s - a[2]) * (s - a[3]) < 0 || fabs(s * (s - a[1]) * (s - a[2]) * (s - a[3])) < e))
        {
            ans[i] = 6;
            continue;
        }
        else if (fabs(a[1] * a[1] - a[2] * a[2] - a[3] * a[3]) < e || fabs(a[2] * a[2] - a[1] * a[1] - a[3] * a[3]) < e || fabs(a[3] * a[3] - a[1] * a[1] - a[2] * a[2]) < e)
        {
            if (fabs(a[1] - a[2]) < e || fabs(a[1] - a[3]) < e || fabs(a[2] - a[3]) < e)
            {
                ans[i] = 3;
                A[i] = sqrt(s * (s - a[1]) * (s - a[2]) * (s - a[3]));
                continue;
            }
            else
            {
                ans[i] = 2;
                A[i] = sqrt(s * (s - a[1]) * (s - a[2]) * (s - a[3]));
                continue;
            }
        }
        else if (fabs(a[1] - a[2]) < e || fabs(a[2] - a[3]) < e || fabs(a[1] - a[3]) < e)
        {
            if (fabs(a[1] - a[2]) < e && fabs(a[2] - a[3]) < e)
            {
                ans[i] = 4;
                A[i] = sqrt(s * (s - a[1]) * (s - a[2]) * (s - a[3]));
                continue;
            }
            else
            {
                ans[i] = 1;
                A[i] = sqrt(s * (s - a[1]) * (s - a[2]) * (s - a[3]));
                continue;
            }
        }
        else
        {
            ans[i] = 5;
            A[i] = sqrt(s * (s - a[1]) * (s - a[2]) * (s - a[3]));
            continue;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        switch (ans[i])
        {
        case 1:
            printf("isosceles triangle, ");
            printf("%.1lf\n", A[i]);
            break;
        case 2:
            printf("right triangle, ");
            printf("%.1lf\n", A[i]);
            break;
        case 3:
            printf("isosceles right triangle, ");
            printf("%.1lf\n", A[i]);
            break;
        case 4:
            printf("equilateral triangle, ");
            printf("%.1lf\n", A[i]);
            break;
        case 5:
            printf("general triangle, ");
            printf("%.1lf\n", A[i]);
            break;
        case 6:
            printf("no triangle\n");
            break;
        }
    }
    return 0;
}
