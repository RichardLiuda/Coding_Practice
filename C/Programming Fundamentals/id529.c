#include <stdio.h>
#include <string.h>
#include <math.h>

double ans;
char s[1145];

double strToDouble(char str[])
{
    ans = 0;
    int nag = 0;
    int temp;
    if (str == 0)
        return ans;
    if (str[0] == '-')
        nag = 1;
    for (int i = nag; i < strlen(str); i++)
    {
        if (str[i] == '.')
        {
            temp = i;
            break;
        }
        if (str[i] <= '9' && str[i] >= '0')
            ans = ans * 10 + (str[i] - '0');
    }
    int temp2 = 0;
    for (int i = temp + 1; i < strlen(str); i++)
    {
        if (str[i] <= '9' && str[i] >= '0')
        {
            temp2++;
            ans += (str[i] - '0') / (pow(10, temp2));
        }
    }
    if (nag)
        ans *= -1;
    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    while (gets(s))
    {
        printf("%g\n", strToDouble(s));
    }
    return 0;
}