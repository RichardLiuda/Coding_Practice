#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    bool flag[n];
    memset(flag, false, sizeof(flag));
    char s[n + 1];
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= 5; j++)
            cin >> s[j];
        if (s[2] == 'B' && s[3] == 'A' || s[2] != 'B' && s[3] != 'A')
            continue;
        if (s[2] == 'B' && s[4] == 'E' || s[2] != 'B' && s[4] != 'E')
            continue;
        if (s[1] == 'C' && s[2] == 'D' || s[1] != 'C' && s[2] != 'D')
            continue;
        if (s[5] == 'C' && s[3] == 'D' || s[5] != 'C' && s[3] != 'D')
            continue;
        if (s[4] == 'E' && s[1] == 'A' || s[4] != 'E' && s[1] != 'A')
            continue;
        flag[i] = true;
    }
    for (int i = 0; i < n; i++)
    {
        if (flag[i])
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
