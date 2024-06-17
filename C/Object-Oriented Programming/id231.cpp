#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef double db;
// #define int long long

class Register
{
protected:
    int value;

public:
    Register(int v) : value(v) {}
    void increment() { value++; }
};

class Calculator : public Register
{
    int min_val, max_val;

public:
    Calculator(int v, int mx) : Register(v), min_val(0), max_val(mx) {}
    void increment()
    {
        if (value >= min_val && value < max_val)
            value++;
        else
            value = min_val;
    }
    int getVal() { return value; }
};

class Clock
{
    Calculator hour, minute, second;

public:
    Clock(int h, int m, int s) : hour(Calculator(h, 23)), minute(Calculator(m, 59)), second(Calculator(s, 59)) {}
    void Time(int s)
    {
        while (s--)
        {
            second.increment();
            if (second.getVal() == 0)
            {
                minute.increment();
                if (minute.getVal() == 0)
                {
                    hour.increment();
                }
            }
        }
        cout << hour.getVal() << ":" << minute.getVal() << ":" << second.getVal() << endl;
    }
};

void QAQ()
{
    int h, m, s;
    cin >> h >> m >> s;
    Clock clock(h, m, s);
    int tm;
    cin >> tm;
    clock.Time(tm);
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
    while (t--)
    {
        QAQ();
    }
    return 0;
}