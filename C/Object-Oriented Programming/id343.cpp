#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef double db;
#define int long long

template <class T>
class BoundArray
{
    vector<T> a;
    bool is_end;

public:
    BoundArray(vector<T> &a) : a(a), is_end(false) {}
    void sort()
    {
        for (int i = 0; i < a.size(); i++)
        {
            for (int j = i + 1; j < a.size(); j++)
            {
                if (a[i] > a[j])
                {
                    swap(a[i], a[j]);
                }
            }
        }
        for (auto i : a)
            cout << i << " ";
        cout << endl;
    }
    int _search(T k)
    {
        int ans;
        bool flag = 0;
        for (int i = 0; i < a.size(); i++)
        {
            if (a[i] == k)
            {
                return i;
            }
        }
        return -1;
    }
};

void QAQ()
{
    char op;
    int n;
    cin >> op >> n;
    if (op == 'I')
    {
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        BoundArray<int> b(a);
        b.sort();
        int k;
        cin >> k;
        cout << b._search(k) << endl;
    }
    if (op == 'D')
    {
        vector<double> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        BoundArray<double> b(a);
        b.sort();
        double k;
        cin >> k;
        cout << b._search(k) << endl;
    }
    if (op == 'C')
    {
        vector<char> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        BoundArray<char> b(a);
        b.sort();
        char k;
        cin >> k;
        cout << b._search(k) << endl;
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