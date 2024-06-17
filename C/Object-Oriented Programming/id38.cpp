#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef double db;
#define int long long

void sortt(int &x, int &y, int &z)
{
    if (x < y)
        swap(x, y);
    if (x < z)
        swap(x, z);
    if (y < z)
        swap(y, z);
}

void QAQ()
{
    int x, y, z;
    cin >> x >> y >> z;
    sortt(x, y, z);
    cout << x << " " << y << " " << z << endl;
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
        QAQ();
    }
    return 0;
}