#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef double db;
// #define int long long

class Clock
{
    int hour, minute, second;

public:
    Clock() {}
    // Clock(int h, int m, int s) : hour(h), minute(m), second(s) {}
    Clock &operator++()
    {
        second++;
        if (second >= 60)
        {
            minute += second / 60;
            if (minute >= 60)
            {
                hour += minute / 60;
                if (hour >= 12)
                    hour = 0;
                minute = 0;
            }
            second = 0;
        }
        return *this;
    }
    Clock operator--(int)
    {
        Clock tmp(*this);
        second--;
        if (second < 0)
        {
            minute--;
            if (minute < 0)
            {
                hour--;
                if (hour < 0)
                    hour = 11;
                minute = 59;
            }
            second = 59;
        }
        return tmp;
    }
    friend istream &operator>>(istream &in, Clock &ck);
    friend ostream &operator<<(ostream &out, Clock &ck);
};
istream &operator>>(istream &in, Clock &ck)
{
    in >> ck.hour >> ck.minute >> ck.second;
    return in;
}
ostream &operator<<(ostream &out, Clock &ck)
{
    out << ck.hour << ":" << ck.minute << ":" << ck.second;
    return out;
}

void QAQ()
{
    Clock ck;
    cin >> ck;
    int t;
    cin >> t;
    while (t--)
    {
        int op;
        cin >> op;
        if (op > 0)
        {
            while (op--)
                ++ck;
        }
        else
        {
            while (op++ < 0)
                ck--;
        }
        cout << ck << endl;
    }
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