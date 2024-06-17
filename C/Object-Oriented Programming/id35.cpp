#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef double db;
#define int long long

void QAQ()
{
    int n, m;
    cin >> m >> n;
    int **p = new int *[n];
    for (int i = 0; i < m; i++)
        p[i] = new int[n];
    int maxx = 0, minn = INT_MAX;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> p[i][j];
            maxx = max(maxx, p[i][j]);
            minn = min(minn, p[i][j]);
        }
    }
    cout << minn << " " << maxx << endl;
    for (int i = 0; i < m; i++)
        delete[] p[i];
    delete[] p;
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