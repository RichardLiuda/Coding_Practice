#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef double db;
#define int long long

class CDate
{
    int year, month, day;

public:
    CDate(int y, int m, int d) : year(y), month(m), day(d) {}
    int getyear() { return year; }
    int getmonth() { return month; }
    int getday() { return day; }
};

class Pet
{
protected:
    string name;   // 姓名
    float length;  // 身长
    float weight;  // 体重
    CDate current; // 开始记录时间
                   // （日期类CDate包含年、月、日三个私有数据，其他方法根据需要自拟。）
public:
    Pet(string n, float l, float w, CDate c) : name(n), length(l), weight(w), current(c) {}
    virtual void display(CDate day) = 0; // 输出目标日期时宠物的身长和体重
};

class Cat : public Pet
{
public:
    Cat(string n, float l, float w, CDate c) : Pet(n, l, w, c) {}
    void display(CDate day)
    {
        if (current.getyear() > day.getyear())
        {
            cout << "error" << endl;
            return;
        }
        if (current.getyear() == day.getyear())
        {
            if (current.getmonth() > day.getmonth())
            {
                cout << "error" << endl;
                return;
            }
            if (current.getmonth() == day.getmonth())
            {
                if (current.getday() > day.getday())
                {
                    cout << "error" << endl;
                    return;
                }
            }
        }
        int days = 0;
        int months[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        for (int i = day.getyear(); i < current.getyear(); i++)
        {
            days += (i % 400 == 0 || (i % 4 == 0 && i % 100 != 0)) ? 366 : 365;
        }
        for (int i = 1; i < current.getmonth(); i++)
        {
            days -= months[i];
            if ((current.getyear() % 4 == 0 && current.getyear() % 100 != 0 || current.getyear() % 400 == 0) && i == 2)
                days--;
        }
        days -= current.getday();
        for (int i = 1; i < day.getmonth(); i++)
        {
            days += months[i];
            if ((current.getyear() % 4 == 0 && day.getyear() % 100 != 0 || day.getyear() % 400 == 0) && i == 2)
                days++;
        }
        days += day.getday();
        float l = length + days * 0.1, w = weight + days * 0.2;
        cout << name << " after " << days << " day: length=" << fixed << setprecision(2) << l << ",weight=" << w << endl;
    }
};

class Dog : public Pet
{
public:
    Dog(string n, float l, float w, CDate c) : Pet(n, l, w, c) {}
    void display(CDate day)
    {
        if (current.getyear() > day.getyear())
        {
            cout << "error" << endl;
            return;
        }
        if (current.getyear() == day.getyear())
        {
            if (current.getmonth() > day.getmonth())
            {
                cout << "error" << endl;
                return;
            }
            if (current.getmonth() == day.getmonth())
            {
                if (current.getday() > day.getday())
                {
                    cout << "error" << endl;
                    return;
                }
            }
        }
        int days = 0;
        int months[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        for (int i = day.getyear(); i < current.getyear(); i++)
        {
            days += (i % 400 == 0 || (i % 4 == 0 && i % 100 != 0)) ? 366 : 365;
        }
        for (int i = 1; i < current.getmonth(); i++)
        {
            days -= months[i];
            if ((current.getyear() % 4 == 0 && current.getyear() % 100 != 0 || current.getyear() % 400 == 0) && i == 2)
                days--;
        }
        days -= current.getday();
        for (int i = 1; i < day.getmonth(); i++)
        {
            days += months[i];
            if ((current.getyear() % 4 == 0 && day.getyear() % 100 != 0 || day.getyear() % 400 == 0) && i == 2)
                days++;
        }
        days += day.getday();
        float l = length + days * 0.2, w = weight + days * 0.1;
        cout << name << " after " << days << " day: length=" << fixed << setprecision(2) << l << ",weight=" << w << endl;
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
    int t = 1;
    cin >> t;
    int y, m, d;
    cin >> y >> m >> d;
    CDate start(y, m, d);
    Pet *p;
    while (t--)
    {
        int type;
        string name;
        float length, weight;
        cin >> type >> name >> length >> weight >> y >> m >> d;
        CDate day(y, m, d);
        if (type == 1)
        {
            Cat c(name, length, weight, start);
            p = &c;
            p->display(day);
        }
        else
        {
            Dog d(name, length, weight, start);
            p = &d;
            p->display(day);
        }
    }
    return 0;
}