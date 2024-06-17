#include <bits/stdc++.h>
using namespace std;
const double N = 1e5 + 10;
typedef double db;
#define int long long
#define pi 3.14

class Geometry
{
public:
    virtual double getArea() = 0; // 计算面积，结果保留小数点后两位
};

class Rect : public Geometry
{
    double length, width;

public:
    Rect(double l, double w)
    {
        length = l;
        width = w;
    }
    double getArea()
    {
        return length * width;
    }
};

class Circle : public Geometry
{
    double radius;

public:
    Circle(double r)
    {
        radius = r;
    }
    double getArea()
    {
        return pi * radius * radius;
    }
};

// 以Geometry为基类，构建出Rect（矩形，数据成员为长和宽）和Circle（圆，数据成员为半径）两个类，重写getArea() 方法，其他方法根据需要自拟。

// 写一个TotalArea类，该类结构如下：

class TotalArea
{
public:
    static void computerMaxArea(Geometry **t, double n); // t为基类二级指针，指向一个基类动态数组，数组的每个元素指向一个子类图形，n为数组的大小
};

void TotalArea::computerMaxArea(Geometry **t, double n)
{
    double maxx = 0;
    for (int i = 0; i < n; i++)
    {
        if (t[i]->getArea() > maxx)
            maxx = t[i]->getArea();
    }
    cout << fixed << setprecision(2) << "最大面积=" << maxx << endl;
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
    Geometry *p[t];
    for (int i = 0; i < t; i++)
    {
        double type;
        cin >> type;
        if (type == 1)
        {
            double l, w;
            cin >> l >> w;
            p[i] = new Rect(l, w);
        }
        if (type == 2)
        {
            double r;
            cin >> r;
            p[i] = new Circle(r);
        }
    }
    TotalArea::computerMaxArea(p, t);
    return 0;
}