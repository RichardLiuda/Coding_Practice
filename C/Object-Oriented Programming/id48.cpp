#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef double db;
#define int long long

pair<int, int> opt[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int n;

void printt(int **p)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << p[i][j];
            if (j == n)
                cout << endl;
            else
                cout << " ";
        }
    }
    cout << endl;
}

void QAQ()
{
    cin >> n;
    int **p = new int *[n + 2];
    for (int i = 0; i < n + 2; i++)
    {
        p[i] = new int[n + 2];
        if (i == 0 || i == n + 1)
            memset(p[i], -1, sizeof(int) * (n + 2));
        else
        {
            memset(p[i], 0, sizeof(int) * (n + 2));
            p[i][0] = -1;
            p[i][n + 1] = -1;
        }
    }
    int x = 1;
    int op = 0;
    int i = 1,
        j = 1;
    // printt(p);
    while (x <= n * n)
    {
        p[i][j] = x++;
        if (p[i + opt[op].first][j + opt[op].second] != 0)
            op = (op + 1) % 4;
        i += opt[op].first;
        j += opt[op].second;
    }
    printt(p);
    for (int i = 0; i < n + 2; i++)
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