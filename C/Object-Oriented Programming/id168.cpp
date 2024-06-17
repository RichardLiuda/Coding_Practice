#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef double db;
#define int long long

class CRect;

class CPoint
{
private:
    int x, y;

public:
    CPoint(int x, int y) : x(x), y(y) {}
    ~CPoint() {}
    friend bool check(CRect, CRect);
};

class CRect
{
private:
    CPoint p1, p2;

public:
    CRect(int x1, int y1, int x2, int y2) : p1(x1, y1), p2(x2, y2) {}
    ~CRect() {}
    friend bool check(CRect, CRect);
};

bool check(CRect r1, CRect r2)
{
    if ((((r2.p1.x - r1.p1.x) * (r2.p1.x - r1.p2.x) <= 0) || ((r2.p2.x - r1.p1.x) * (r2.p2.x - r1.p2.x) <= 0)) && (((r2.p1.y - r1.p1.y) * (r2.p1.y - r1.p2.y) <= 0) || ((r2.p2.y - r1.p1.y) * (r2.p2.y - r1.p2.y) <= 0)))
        return 1;
    return 0;
}

void QAQ()
{
    int x1, y1, x2, y2, x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    CRect r1(x1, y1, x2, y2), r2(x3, y3, x4, y4);
    if (check(r1, r2))
        cout << "overlapped" << endl;
    else
        cout << "not overlapped" << endl;
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