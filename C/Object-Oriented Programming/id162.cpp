#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef double db;
#define int long long

class Complex
{
private:
    double real, imag;

public:
    Complex()
    {
        real = 0;
        imag = 0;
    };
    Complex(double r, double i)
    {
        real = r;
        imag = i;
    }
    friend Complex addCom(Complex c1, Complex c2);
    friend void outCom(Complex c);
};

Complex addCom(Complex c1, Complex c2)
{
    return Complex(c1.real + c2.real, c1.imag + c2.imag);
}
void outCom(Complex c)
{
    cout << "(" << c.real << "," << c.imag << ")" << endl;
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int a, b;
    cin >> a >> b;
    Complex c(a, b);
    int t = 1;
    cin >> t;
    while (t--)
    {
        char op;
        cin >> op;
        int x, y;
        cin >> x >> y;
        if (op == '-')
        {
            y *= -1;
            x *= -1;
        }
        Complex c1(x, y);
        c = addCom(c, c1);
        outCom(c);
    }
    return 0;
}