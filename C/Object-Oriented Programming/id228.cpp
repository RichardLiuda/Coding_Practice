#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef double db;
#define int long long
#define pi 3.14

class CPoint
{
    int x, y;

public:
    CPoint(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    void print()
    {
        cout << "(" << x << "," << y << "),";
    }
};

class CCircle : public CPoint
{
    int r;

public:
    CCircle(int x, int y, int r) : CPoint(x, y), r(r) {}
    float getArea() { return pi * r * r; }
    void print()
    {
        CPoint::print();
        cout << r;
    }
};

class Cylinder : public CCircle
{
    int h;

public:
    Cylinder(int x, int y, int r, int h) : CCircle(x, y, r), h(h) {}
    void print()
    {
        CCircle::print();
        cout << "," << h << endl;
    }
    float getVolume() { return getArea() * h; }
};

void QAQ()
{
    int x, y, r;
    cin >> x >> y >> r;
    CCircle c(x, y, r);
    cout << "Circle:";
    c.print();
    cout << endl;
    cout << "Area:" << fixed << setprecision(2) << c.getArea() << endl;
    int h;
    cin >> x >> y >> r >> h;
    Cylinder v(x, y, r, h);
    cout << "Cylinder:";
    v.print();
    cout << "Volume:" << fixed << setprecision(2) << v.getVolume() << endl;
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
    //    cin>>t;
    while (t--)
    {
        QAQ();
    }
    return 0;
}