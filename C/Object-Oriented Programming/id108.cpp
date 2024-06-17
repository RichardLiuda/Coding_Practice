#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef double db;

class Date
{
private:
    int year, month, day;

public:
    Date()
    {
        year = 0;
        month = 0;
        day = 0;
    };
    Date(int y, int m, int d)
    {
        year = y;
        month = m;
        day = d;
    }
    int GetYear() { return year; }
    int GetMonth() { return month; }
    int GetDay() { return day; }
};

class VIP
{
private:
    string id;
    Date birth;

public:
    VIP()
    {
        id = "";
    }
    VIP(string id, int y, int m, int d) : id(id), birth(y, m, d) {}

    double Discount(Date &d)
    {
        if (d.GetDay() == birth.GetDay() && d.GetMonth() == birth.GetMonth())
            return 0.5;
        else
            return 0.95;
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
    int y, m, d;
    cin >> y >> m >> d;
    Date today(y, m, d);
    int t = 1;
    cin >> t;
    while (t--)
    {
        string id;
        cin >> id;
        int y, m, d;
        cin >> y >> m >> d;
        VIP v(id, y, m, d);
        double disc;
        cin >> disc;
        cout << id << "'s consumption is " << int(disc * v.Discount(today)) << endl;
    }
    return 0;
}