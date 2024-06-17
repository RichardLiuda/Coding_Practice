#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef double db;
#define int long long

class Equation
{
private:
    double a, b, c;

public:
    Equation()
    {
        a = 1;
        b = 1;
        c = 0;
    }
    Equation(double a, double b, double c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }
    void set(double a, double b, double c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }
    void getRoot()
    {
        if (a == 0 && b == 0)
        {
            cout << "No Solution" << endl;
            return;
        }
        else if (a == 0)
        {
            cout << "x=" << fixed << setprecision(2) << -b / c << endl;
            return;
        }
        double del = b * b - 4 * a * c;
        if (del == 0)
            cout << fixed << setprecision(2) << "x1=x2=" << -b / (2 * a) << endl;
        else if (del > 0)
            cout << fixed << setprecision(2) << "x1=" << (-b + sqrt(del)) / (2 * a) << " x2=" << (-b - sqrt(del)) / (2 * a) << endl;
        else
        {
            double x1 = -b / (2 * a);
            double y1 = sqrt(-del) / (2 * a);
            double x2 = x1;
            double y2 = -y1;
            cout << "x1=";
            print(x1, y1);
            cout << " x2=";
            print(x2, y2);
            cout << endl;
        }
    }
    void print(double a, double b)
    {
        if (a == 0 && b == 0)
            cout << fixed << setprecision(2) << "0";
        else if (b == 0)
            cout << fixed << setprecision(2) << a;
        else if (a == 0)
            cout << fixed << setprecision(2) << b << "i";
        else
        {
            cout << a;
            if (b == 1)
                cout << "+i";
            else if (b == -1)
                cout << "-i";
            else
            {
                cout << fixed << setprecision(2) << showpos << b << noshowpos << "i";
            }
        }
    }
};

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
    Equation e;
    while (t--)
    {
        double a, b, c;
        cin >> a >> b >> c;
        e.set(a, b, c);
        e.getRoot();
    }
    return 0;
}