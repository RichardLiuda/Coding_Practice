#include <stdio.h>

char *base[12] = {
    "January",
    "February",
    "March",
    "April",
    "May",
    "June",
    "July",
    "Aguest",
    "September",
    "October",
    "November",
    "December"};
// char *p = base;

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        // p = base;
        int n;
        scanf("%d", &n);
        if (n > 0 && n < 13)
            printf("%s\n", *(base + n - 1));
        else
            printf("error");
    }
    return 0;
}