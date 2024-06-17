#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef double db;
#define int long long

template <class T>
void Next(T &a, int n)
{
    if (!next_permutation(a, a + n))
        sort(a, a + n);
    for (int i = 0; i < n; i++)
        cout << a[i] << (i == n - 1 ? "" : " ");
    cout << endl;
}

void QAQ()
{
    char op;
    int n;
    cin >> op >> n;
    if (op == 'I')
    {
        int *a = new int[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Next(a, n);
    }
    else if (op == 'D')
    {
        double *a = new double[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Next(a, n);
    }
    else if (op == 'C')
    {
        char *a = new char[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Next(a, n);
    }
    else if (op == 'S')
    {
        string *a = new string[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Next(a, n);
    }
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
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