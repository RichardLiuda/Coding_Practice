#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef double db;

template <class T>
bool check(T a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        if (a[i] < a[i - 1])
            return 0;
    }
    return 1;
}

void QAQ()
{
    char op;
    cin >> op;
    int n = 6;
    if (op == 'i')
    {
        int *a = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        cout << (check(a, n) ? "Valid" : "Invalid") << endl;
    }
    else if (op == 'f')
    {
        double *a = new double[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        cout << (check(a, n) ? "Valid" : "Invalid") << endl;
    }
    else if (op == 'c')
    {
        char *a = new char[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        cout << (check(a, n) ? "Valid" : "Invalid") << endl;
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