#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef double db;
#define int long long

class CComplex
{
private:
    int a, b;

public:
    CComplex()
    {
        a = 1;
        b = 1;
    };
    CComplex(int a, int b)
    {
        this->a = a;
        this->b = b;
    }
    CComplex add(CComplex &c)
    {
        return CComplex(a + c.a, b + c.b);
    }
    CComplex sub(CComplex &c)
    {
        return CComplex(a - c.a, b - c.b);
    }
    void print()
    {
        if (a == 0 && b == 0)
            cout << "0" << endl;
        else if (b == 0)
            cout << a << endl;
        else if (a == 0)
            cout << b << "i" << endl;
        else
        {
            cout << a;
            if (b == 1)
                cout << "+i" << endl;
            else if (b == -1)
                cout << "-i" << endl;
            else
            {
                cout << showpos << b << noshowpos << "i" << endl;
            }
        }
    }
};

void QAQ()
{
    int a1, b1, a2, b2;
    cin >> a1 >> b1 >> a2 >> b2;
    CComplex c1(a1, b1), c2(a2, b2);
    cout << "sum:";
    c1.add(c2).print();
    cout << "remainder:";
    c1.sub(c2).print();
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    CComplex defaultc;
    int t = 1;
    cin >> t;
    while (t--)
    {
        QAQ();
    }
    return 0;
}