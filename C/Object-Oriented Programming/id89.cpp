#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef double db;
#define int long long

class CDate
{
public:
    CDate(int m, int d, int y)
    {
        month = m;
        day = d;
        year = y;
        week = 0;
    }
    void print();
    void getWeekofDay();

private:
    int month;
    int day;
    int year;
    int week;
};

void CDate::print()
{
    string we[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    cout << month << "/" << day << "/" << year << ", " << we[week - 1] << endl;
}

void CDate::getWeekofDay()
{
    int _month = month;
    int _year = year;
    if (month <= 2)
    {
        _month += 12;
        _year--;
    }
    week = (day + 2 * _month + 3 * (_month + 1) / 5 + _year + _year / 4 - _year / 100 + _year / 400) % 7 + 1;
}

void QAQ()
{
    int m, d, y;
    cin >> y >> m >> d;
    CDate date(m, d, y);
    date.getWeekofDay();
    date.print();
}

signed main()
{
    //#ifndef ONLINE_JUDGE
    //    freopen("in.in", "r", stdin);
    //    freopen("out.out", "w", stdout);
    //#endif
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