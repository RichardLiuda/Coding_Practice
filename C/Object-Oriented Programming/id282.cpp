#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef double db;
#define int long long

class Shape
{
protected:
    string name;
    double x, y;

public:
    Shape(double x, double y) : x(x), y(y) {}
    virtual void shapeName() = 0;
    virtual double getArea() { return 0.0; }
    virtual double getVolume() { return 0.0; }
    virtual double getX() { return x; }
    virtual double getY() { return y; }
    virtual string getName() { return name; }
};

class Point : public Shape
{
public:
    Point(double x, double y) : Shape(x, y) {}
    void shapeName() { name = "Point"; }
};

class Circle : public Point
{
    double r;

public:
    Circle(double x, double y, double r) : Point(x, y), r(r) {}
    void shapeName() { name = "Circle"; }
    double getArea() { return 3.14159 * r * r; }
    double getR() { return r; }
};

class Cylinder : public Circle
{
    double h;

public:
    Cylinder(double x, double y, double r, double h) : Circle(x, y, r), h(h) {}
    void shapeName() { name = "Cylinder"; }
    double getVolume() { return 3.14159 * getR() * getR() * h; }
    double getArea() { return 2 * 3.14159 * getR() * h + 2 * 3.14159 * getR() * getR(); }
    double getH() { return h; }
};

void Print(Shape *s)
{
    cout << s->getName() << "--(" << s->getX() << "," << s->getY() << ")--" << floor(s->getArea()) << "--" << floor(s->getVolume()) << endl;
}

void QAQ()
{
    double x, y, r, h;
    cin >> x >> y;
    Shape *s;
    s = new Point(x, y);
    s->shapeName();
    Print(s);
    cin >> x >> y >> r;
    s = new Circle(x, y, r);
    s->shapeName();
    Print(s);
    cin >> x >> y >> r >> h;
    s = new Cylinder(x, y, r, h);
    s->shapeName();
    Print(s);
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