#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef double db;
#define int long long

string mname[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

class Date
{
private:
    int year, month, day;

public:
    void set(int y, int m, int d)
    {
        year = y;
        month = m;
        day = d;
    }
    int getyear() { return year; }
    int getmonth() { return month; }
    int getday() { return day; }
};

void printmonth(Date d)
{
    cout << "This month is " << mname[d.getmonth() - 1] << " and next month is " << mname[d.getmonth() % 12] << endl;
}

void printlast(Date d)
{
    int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (d.getyear() % 400 == 0 || (d.getyear() % 4 == 0 && d.getyear() % 100 != 0))
        days[2] = 29;
    int sum = days[d.getmonth()] - d.getday();
    for (int i = d.getmonth() + 1; i <= 12; i++)
    {
        sum += days[i];
    }
    cout << "There are " << sum << " days to the end of the year" << endl;
}

void QAQ()
{
    int y, m, d;
    cin >> y >> m >> d;
    Date d1;
    d1.set(y, m, d);
    printmonth(d1);
    printlast(d1);
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