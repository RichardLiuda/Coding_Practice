#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef double db;
#define int long long

template <class T>
void Select(T a[], int n)
{
    map<T, int> ti;
    for (int i = 0; i < n; i++)
    {
        ti[a[i]]++;
    }
    int __max = 0;
    T ans;
    for (auto i : ti)
    {
        if (i.second > __max)
        {
            __max = i.second;
            ans = i.first;
        }
    }
    cout << ans << " " << __max << endl;
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
        {
            cin >> a[i];
        }
        Select(a, n);
    }
    else if (op == 'D')
    {
        double *a = new double[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Select(a, n);
    }
    else if (op == 'C')
    {
        char *a = new char[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Select(a, n);
    }
    else if (op == 'S')
    {
        string *a = new string[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Select(a, n);
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