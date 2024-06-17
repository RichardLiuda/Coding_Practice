#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef double db;
#define int long long
//-----类定义------
class Point
{
private:
    float x, y;

public:
    void SetPoint(float a, float b);
    float GetX();
    float GetY();
};

class Circle
{
private:
    float x, y, r;

public:
    void SetCenter(float a, float b);
    void SetRadius(float a);
    float GetX();
    float GetY();
    float GetR();
    float GetArea();
    float GetLength();
};
//----类实现------

void Point::SetPoint(float a, float b)
{
    x = a;
    y = b;
}
float Point::GetX()
{
    return x;
}
float Point::GetY()
{
    return y;
}

void Circle::SetCenter(float a, float b)
{
    x = a;
    y = b;
}
void Circle::SetRadius(float a)
{
    r = a;
}
float Circle::GetX()
{
    return x;
}
float Circle::GetY()
{
    return y;
}
float Circle::GetR()
{
    return r;
}
float Circle::GetArea()
{
    return 3.14 * r * r;
}
float Circle::GetLength()
{
    return 2 * 3.14 * r;
}

//-----主函数-----
void QAQ()
{
    Point p;
    Circle c;
    float x, y, r;
    cin >> x >> y >> r;
    c.SetCenter(x, y);
    c.SetRadius(r);
    cin >> x >> y;
    p.SetPoint(x, y);
    cout << fixed << setprecision(2) << c.GetArea() << " " << c.GetLength() << endl;
    if ((p.GetX() - c.GetX()) * (p.GetX() - c.GetX()) + (p.GetY() - c.GetY()) * (p.GetY() - c.GetY()) <= c.GetR() * c.GetR())
        cout << "yes" << endl;
    else
        cout << "no" << endl;
}
signed main()
{
    //#ifndef ONLINE_JUDGE
    //    freopen("in.in", "r", stdin);
    //    freopen("out.out", "w", stdout);
    //#endif
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