#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef double db;
#define int long long

class CTime;
class CDate;

class CDate
{
private:
    int year, month, day;

public:
    CDate(int y, int m, int d)
    {
        year = y;
        month = m;
        day = d;
    }
    friend void Display(CDate &d, CTime &t);
};

class CTime
{
private:
    int hour, minute, second;

public:
    CTime(int h, int m, int s)
    {
        hour = h;
        minute = m;
        second = s;
    }
    friend void Display(CDate &d, CTime &t);
};

void Display(CDate &d, CTime &t)
{
    cout.fill('0');
    cout << d.year << "-" << setw(2) << d.month << "-" << setw(2) << d.day << " ";
    cout << setw(2) << t.hour << ":" << setw(2) << t.minute << ":" << setw(2) << t.second << endl;
}

void QAQ()
{
    int y, m, d, h, min, s;
    cin >> y >> m >> d >> h >> min >> s;
    CDate date(y, m, d);
    CTime time(h, min, s);
    Display(date, time);
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