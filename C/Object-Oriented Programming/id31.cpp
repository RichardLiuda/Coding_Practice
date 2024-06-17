#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef double db;
#define int long long

bool isNumber(char *c)
{
    for (int i = 0; c[i] != '\0'; i++)
    {
        if (c[i] < '0' || c[i] > '9')
            return false;
    }
    return true;
}

int num(char *c)
{
    int res = 0;
    for (int i = 0; c[i] != '\0'; i++)
    {
        res = res * 10 + (c[i] - '0');
    }
    return res;
}

signed main()
{
    //#ifndef ONLINE_JUDGE
    //    freopen("in.in", "r", stdin);
    //    freopen("out.out", "w", stdout);
    //#endif
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        char *p = new char[114];
        cin >> p;
        if (isNumber(p))
            cout << num(p) << endl;
        else
            cout << "-1" << endl;
        delete[] p;
    }
    return 0;
}