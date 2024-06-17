#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef double db;

template <class T>
void Pin(T a[], T b[], int n)
{
    T *ans = new T[2 * n];
    for (int i = 0; i < n; i++)
    {
        ans[i] = b[i];
    }
    for (int i = 0; i < n; i++)
    {
        ans[i + n] = a[i];
    }
    for (int i = 0; i < 2 * n; i++)
    {
        cout << ans[i];
    }
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
        int *b = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        Pin(a, b, n);
    }
    else if (op == 'D')
    {
        double *a = new double[n];
        double *b = new double[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        Pin(a, b, n);
    }
    else if (op == 'C')
    {
        char *a = new char[n];
        char *b = new char[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        Pin(a, b, n);
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