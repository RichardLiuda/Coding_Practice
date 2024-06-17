#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef float db;

template <class T>
void __sort(T a[], int beg, int end, int n)
{
    if (beg < end)
    {
        int _beg = max(beg, 0), _end = min(end, n);
        sort(a + _beg, a + _end);
    }
    cout << "[";
    for (int i = 0; i < n; i++)
        cout << fixed << setprecision(1) << a[i] << (i == n - 1 ? "]" : ", ");
    cout << endl;
}

void QAQ()
{
    string op;
    int n;
    cin >> op;
    if (op == "int")
    {
        char c;
        int beg, end;
        cin >> n >> c >> beg >> c >> end >> c >> c;
        int *a = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        __sort(a, beg, end, n);
    }
    else if (op == "float")
    {
        char c;
        int beg, end;
        cin >> n >> c >> beg >> c >> end >> c >> c;
        float *a = new float[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        __sort(a, beg, end, n);
    }
    else if (op == "string")
    {
        char c;
        int beg, end;
        cin >> n >> c >> beg >> c >> end >> c >> c;
        string *a = new string[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        __sort(a, beg, end, n);
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