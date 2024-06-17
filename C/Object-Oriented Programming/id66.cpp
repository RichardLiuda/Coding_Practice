#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef double db;
#define int long long

void QAQ()
{
    int a, b, c;
    cin >> a >> b >> c;
    int *p1 = &a, *p2 = &b, *p3 = &c;
    for (int i = 0; i < 3; i++)
    {
        if (*p1 < *p2)
            swap(p1, p2);
        if (*p2 < *p3)
            swap(p2, p3);
        if (*p1 < *p3)
            swap(p1, p3);
    }
    cout << *p1 << " " << *p2 << " " << *p3 << " " << endl;
}

signed main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("in.in", "r", stdin);
    //     freopen("out.out", "w", stdout);
    // #endif
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