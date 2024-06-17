// 补充头文件、点类和矩形类
/********** Write your code here! **********/
#include <bits/stdc++.h>
using namespace std;

class CPoint
{
    int x, y;

public:
    CPoint(int x = 0, int y = 0)
    {
        this->x = x;
        this->y = y;
    }
    int getX() const
    {
        return x;
    }
    int getY() const
    {
        return y;
    }
};

class CRectangle
{
    CPoint leftPoint, rightPoint;

public:
    CRectangle(int x1, int y1, int x2, int y2) : leftPoint(CPoint(x1, y1)), rightPoint(CPoint(x2, y2)) {}
    bool operator>(const CPoint &rhs)
    {
        return (leftPoint.getX() <= rhs.getX() && rightPoint.getX() >= rhs.getX()) && (leftPoint.getY() >= rhs.getY() && rightPoint.getY() <= rhs.getY());
    }
    bool operator>(CRectangle &rhs)
    {
        return (*this > rhs.leftPoint) && (*this > rhs.rightPoint);
    }
    bool operator==(CRectangle &rhs)
    {
        return (leftPoint.getX() == rhs.leftPoint.getX() && leftPoint.getY() == rhs.leftPoint.getY() && rightPoint.getX() == rhs.rightPoint.getX() && rightPoint.getY() == rhs.rightPoint.getY());
    }
    bool operator*(CRectangle &rhs)
    {
        for (int i = leftPoint.getX(); i <= rightPoint.getX(); i++)
            for (int j = leftPoint.getY(); j >= rightPoint.getY(); j--)
            {
                if (rhs.leftPoint.getX() <= i && rhs.rightPoint.getX() >= i && rhs.leftPoint.getY() >= j && rhs.rightPoint.getY() <= j)
                    return true;
            }
        return false;
    }
    operator int()
    {
        return abs(leftPoint.getX() - rightPoint.getX()) * abs(leftPoint.getY() - rightPoint.getY());
    }
    friend ostream &operator<<(ostream &out, CRectangle &rhs);
};

ostream &operator<<(ostream &out, CRectangle &rhs)
{
    out << rhs.leftPoint.getX() << " " << rhs.leftPoint.getY() << " " << rhs.rightPoint.getX() << " " << rhs.rightPoint.getY();
    return out;
}
/*******************************************/
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    int t, x1, x2, y1, y2;
    cin >> t;

    while (t--)
    {
        cin >> x1 >> y1 >> x2 >> y2; // 矩形1的左上角、右下角
        CRectangle rect1(x1, y1, x2, y2);
        cin >> x1 >> y1 >> x2 >> y2; // 矩形2的左上角、右下角
        CRectangle rect2(x1, y1, x2, y2);

        cout << "矩形1:" << rect1 << " " << (int)rect1 << endl;
        cout << "矩形2:" << rect2 << " " << (int)rect2 << endl;

        if (rect1 == rect2) // 判两个矩形相等
            cout << "矩形1和矩形2相等" << endl;
        else if (rect2 > rect1) // 判矩形2包含矩形1
            cout << "矩形2包含矩形1" << endl;
        else if (rect1 > rect2) // 判矩形1包含矩形2
            cout << "矩形1包含矩形2" << endl;
        else if (rect1 * rect2) // 判矩形1和矩形2相交
            cout << "矩形1和矩形2相交" << endl;
        else
            cout << "矩形1和矩形2不相交" << endl;
        cout << endl;
    }
    return 0;
}
