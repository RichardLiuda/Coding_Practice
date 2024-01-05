#include <stdio.h>

int main()
{
    int n;
    float h;
    scanf("%f%d", &h, &n);
    float x = h;
    // x = (int)((x * 1000 + 5) / 10) / 100.0;
    for (int i = 2; i <= n; i++)
    {
        h = h / 2;
        h = (int)((h * 1000 + 5) / 10) / 100.0;
        x += 2 * h;
        x = (int)((x * 1000 + 5) / 10) / 100.0;
    }
    h /= 2;
    h = (int)((h * 1000 + 5) / 10) / 100.0;
    printf("%.2f\n%.2f", x, h);
    return 0;
}
