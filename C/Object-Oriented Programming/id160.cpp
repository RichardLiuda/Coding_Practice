#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef double db;
#define int long long

class Point
{
private:
    double x, y;

public:
    Point(double xx, double yy)
    {
        x = xx;
        y = yy;
    }
    friend double Distance(Point &a, Point &b);
};

double Distance(Point &a, Point &b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

void QAQ()
{
    int x, y;
    cin >> x >> y;
    Point a(x, y);
    cin >> x >> y;
    Point b(x, y);
    cout << fixed << (int)Distance(a, b) << endl;
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