#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef double db;
#define int long long

class str
{
    char *p;

public:
    str() {}
    str(char *s)
    {
        p = s;
    }
    friend bool operator>(str &, str &);
    friend bool operator<(str &, str &);
    friend bool operator==(str &, str &);
    void show() { cout << p; }
};

bool operator>(str &a, str &b)
{
    return strcmp(a.p, b.p) > 0;
}

bool operator<(str &a, str &b)
{
    return strcmp(a.p, b.p) < 0;
}

bool operator==(str &a, str &b)
{
    return strcmp(a.p, b.p) == 0;
}

void QAQ()
{
    char *p1 = new char[100], *p2 = new char[100], *p3 = new char[100];
    cin.getline(p1, 100);
    cin.getline(p2, 100);
    cin.getline(p3, 100);
    str a(p1), b(p2), c(p3);
    ((a > b) ? a : b).show();
    cout << endl;
    ((a < c) ? a : c).show();
    cout << endl;
    ((b == c) ? b : c).show();
    cout << endl;
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
    // cin >> t;
    while (t--)
    {
        QAQ();
    }
    return 0;
}