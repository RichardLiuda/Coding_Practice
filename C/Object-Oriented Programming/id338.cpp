#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef double db;
#define int long long

template <class T>
int check(T a[], T key, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == key)
        {
            return i + 1;
        }
    }
    return 0;
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
        int key;
        cin >> key;
        cout << check(a, key, n) << endl;
    }
    else if (op == 'D')
    {
        double *a = new double[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        double key;
        cin >> key;
        cout << check(a, key, n) << endl;
    }
    else if (op == 'C')
    {
        char *a = new char[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        char key;
        cin >> key;
        cout << check(a, key, n) << endl;
    }
    else if (op == 'S')
    {
        string *a = new string[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        string key;
        cin >> key;
        cout << check(a, key, n) << endl;
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