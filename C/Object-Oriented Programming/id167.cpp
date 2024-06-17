#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef double db;
#define int long long

class Time
{
private:
    int h, m, s;

public:
    Time(int h, int m, int s)
    {
        this->h = h;
        this->m = m;
        this->s = s;
    }
    friend int Subtime(Time *a, Time *b);
    int getHour() { return h; }
    int getMin() { return m; }
    int getSec() { return s; }
};

int Subtime(Time *a, Time *b)
{
    return abs((a->h - b->h) * 3600 + (a->m - b->m) * 60 + (a->s - b->s));
}

void QAQ()
{
    int h, m, s;
    cin >> h >> m >> s;
    Time *a = new Time(h, m, s);
    cin >> h >> m >> s;
    Time *b = new Time(h, m, s);
    cout << a->getHour() << "时" << a->getMin() << "分" << a->getSec() << "秒"
         << "--" << b->getHour() << "时" << b->getMin() << "分" << b->getSec() << "秒时间差为" << Subtime(a, b) << "秒" << endl;
    delete a, b;
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