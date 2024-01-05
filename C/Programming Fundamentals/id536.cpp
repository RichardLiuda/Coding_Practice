#include <bits/stdc++.h>
using namespace std;

void itostr(int num, char str[])
{
    bool flag;
    // if (!num && !len(num))
    // {
    //     str[0] = '0';
    //     str[1] = '\0';
    //     return;
    // }
    if (!num)
    {
        // str[strlen(str)] = num % 10 + '0';
        // str[strlen(str) + 1] = '\0';
        return;
    }
    itostr(num / 10, str);

    str[strlen(str)] = num % 10 + '0';
    str[strlen(str) + 1] = '\0';
}

int main()
{
    const int SIZE = 20;
    int t, num;
    char str[SIZE];

    cin >> t;
    while (t--)
    {
        cin >> num;
        itostr(num, str);
        cout << str << endl;
    }
    return 0;
}