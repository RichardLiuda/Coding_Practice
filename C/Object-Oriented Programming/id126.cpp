#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef double db;
#define int long long

class CDate
{
private:
    int year, month, day;

public:
    CDate() {}
    CDate(int y, int m, int d)
    {
        year = y;
        month = m;
        day = d;
    }
    bool isLeapYear() { return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0; }
    int getYear() { return year; }
    int getMonth() { return month; }
    int getDay() { return day; }
    int getDayofYear() // 计算日期从当年1月1日算起的天数
    {
        int i, sum = day;
        int a[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int b[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        if (isLeapYear())
            for (i = 0; i < month; i++)
                sum += b[i];
        else
            for (i = 0; i < month; i++)
                sum += a[i];

        return sum;
    }
};

CDate today(2015, 4, 7);

class Software
{
private:
    string name;
    char type;
    CDate ddl;
    char st;

public:
    Software(string n, char t, CDate d, char s)
    {
        name = n;
        type = t;
        ddl = d;
        st = s;
    }
    Software(Software &s)
    {
        name = s.name;
        type = 'B';
        ddl = s.ddl;
        st = 'H';
    }
    void print()
    {
        cout << "name:" << name << endl;
        cout << "type:" << (type == 'O' ? "original" : (type == 'T' ? "trial" : "backup")) << endl;
        cout << "media:" << (st == 'D' ? "optical disk" : (st == 'H' ? "hard disk" : "USB disk")) << endl;
        if (ddl.getDay() == 0 && ddl.getMonth() == 0 && ddl.getYear() == 0)
            cout << "this software has unlimited use" << endl;
        else
        {
            bool flag = ddl.getYear() > today.getYear();
            if (ddl.getYear() == today.getYear())
            {
                flag = ddl.getMonth() > today.getMonth();
                if (ddl.getMonth() == today.getMonth())
                    flag = ddl.getDay() > today.getDay();
            }
            if (!flag)
                cout << "this software has expired" << endl;
            else
                cout << "this software is going to be expired in " << ddl.getDayofYear() + (ddl.getYear() - today.getYear()) * 365 - today.getDayofYear() << " days" << endl;
        }
        cout << endl;
    }
};

void QAQ()
{
    string name;
    cin >> name;
    char t, s;
    cin >> t >> s;
    int y, m, d;
    cin >> y >> m >> d;
    CDate ddl(y, m, d);
    Software a(name, t, ddl, s);
    a.print();
    Software b(a);
    b.print();
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