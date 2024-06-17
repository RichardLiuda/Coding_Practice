#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef double db;
#define int long long

class Complex
{
    int real, imag;

public:
    Complex(int r, int i) : real(r), imag(i) {}
    Complex operator+(Complex &c)
    {
        return Complex(real + c.real, imag + c.imag);
    }
    Complex operator-(Complex &c)
    {
        return Complex(real - c.real, imag - c.imag);
    }
    Complex operator*(Complex &c)
    {
        return Complex(real * c.real - imag * c.imag, real * c.imag + imag * c.real);
    }
    void print()
    {
        cout << "Real=" << real << " " << "Image=" << imag << endl;
    }
};

void QAQ()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    Complex c1(a, b), c2(c, d);
    (c1 + c2).print();
    (c1 - c2).print();
    (c1 * c2).print();
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
    // cin >> t;
    while (t--)
    {
        QAQ();
    }
    return 0;
}