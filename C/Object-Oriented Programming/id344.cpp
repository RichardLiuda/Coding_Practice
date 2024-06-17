#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef double db;
#define int long long
class CClock
{
    int num1, num2, num3;

public:
    CClock(int num1 = 0, int num2 = 0, int num3 = 0) : num1(num1), num2(num2), num3(num3) {}
    friend ostream &operator<<(ostream &os, const CClock &clock);
    int getnum1() const { return num1; }
    int getnum2() const { return num2; }
    int getnum3() const { return num3; }
};

class CRmb
{
    int num1, num2, num3;

public:
    CRmb(int num1 = 0, int num2 = 0, int num3 = 0) : num1(num1), num2(num2), num3(num3) {}
    int getnum1() const { return num1; }
    int getnum2() const { return num2; }
    int getnum3() const { return num3; }
    friend ostream &operator<<(ostream &os, const CRmb &rmb);
};

ostream &operator<<(ostream &out, const CClock &a)
{
    out << a.getnum1() << " " << a.getnum2() << " " << a.getnum3();
    return out;
}
ostream &operator<<(ostream &out, const CRmb &a)
{
    out << a.getnum1() << " " << a.getnum2() << " " << a.getnum3();
    return out;
}

template <class T>
T add(T a, T b, int mod)
{
    return (T(((a.getnum3() + b.getnum3() >= 1) ? (a.getnum2() + b.getnum2() + 1) : (a.getnum2() + b.getnum2())) >= mod ? a.getnum1() + b.getnum1() + 1 : a.getnum1() + b.getnum1(), (a.getnum3() + b.getnum3() >= mod) ? (a.getnum2() + b.getnum2() + 1) % mod : (a.getnum2() + b.getnum2()) % mod, (a.getnum3() + b.getnum3()) % mod));
}

void QAQ()
{
    int x1, y1, z1, x2, y2, z2;
    cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
    CClock c1(x1, y1, z1), c2(x2, y2, z2), c;
    c = add(c1, c2, 60);
    cout << c << endl;
    cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
    CRmb r1(x1, y1, z1), r2(x2, y2, z2), r;
    r = add(r1, r2, 10);
    cout << r << endl;
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