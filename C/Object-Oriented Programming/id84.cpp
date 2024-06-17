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
    Point() { x = 0, y = 0; }
    Point(double x, double y) { this->x = x, this->y = y; }
    double getX() { return x; }
    double getY() { return y; }
    void setXY(double x, double y) { this->x = x, this->y = y; }
    void setX(double x) { this->x = x; }
    void setY(double y) { this->y = y; }
    double getDisTo(Point &a) { return sqrt((x - a.getX()) * (x - a.getX()) + (y - a.getY()) * (y - a.getY())); }
};

class Circle
{
private:
    Point center;
    double radius;

public:
    Circle() { center = Point(), radius = 1; }
    Circle(double x, double y, double radius) : center(x, y), radius(radius) {}
    double getArea() { return 3.1415926 * radius * radius; }
    void moveCenterTo(double x, double y) { center.setXY(x, y); }
    bool contain(Point &a) { return center.getDisTo(a) <= radius; }
};

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int x, y, r;
    cin >> x >> y >> r;
    Circle c(x, y, r);
    int t = 1;
    cin >> t;
    vector<Point> pot(t);
    for (int i = 0; i < t; i++)
    {
        int x1, y1;
        cin >> x1 >> y1;
        pot[i] = Point(x1, y1);
    }
    for (int i = 0; i < t; i++)
    {
        if (c.contain(pot[i]))
            cout << "inside" << endl;
        else
            cout << "outside" << endl;
    }
    cout << "after move the centre of circle:" << endl;
    cin >> x >> y;
    c.moveCenterTo(x, y);
    for (int i = 0; i < t; i++)
    {
        if (c.contain(pot[i]))
            cout << "inside" << endl;
        else
            cout << "outside" << endl;
    }
    return 0;
}