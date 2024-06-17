#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef double db;
#define int long long

void QAQ()
{
    int n;
    cin >> n;
    int *mark = new int[n + 1];
    for (int i = 0; i < n; i++)
        cin >> mark[i];
    int *p = mark + n / 2;
    int check;
    cin >> check;
    cout << *(--p) << " ";
    p++;
    p++;
    cout << *p << endl;
    p--;
    int i = check - 1 - (p - mark);
    p += i;
    cout << *p << endl;
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