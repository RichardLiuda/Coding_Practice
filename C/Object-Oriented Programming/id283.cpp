#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef double db;
#define int long long

class Schedule;

vector<Schedule> v;

class Date
{
protected:
    int year, month, day;

private:
public:
    Date(int y, int m, int d) : year(y), month(m), day(d) {}
    ~Date() {}
    friend bool before(const Schedule, const Schedule);
};

class Time
{
protected:
    int hour, minute, second;

private:
public:
    Time(int h, int m, int s) : hour(h), minute(m), second(s) {}
    ~Time() {}
    friend bool before(const Schedule, const Schedule);
};

class Schedule : public Date, public Time
{
private:
    int ID;

public:
    Schedule(int y, int m, int d, int h, int min, int s, int id) : Date(y, m, d), Time(h, min, s), ID(id) {}
    ~Schedule() {}
    int getYear() const { return year; }
    int getMonth() const { return month; }
    int getDay() const { return day; }
    int getHour() const { return hour; }
    int getMinute() const { return minute; }
    int getSecond() const { return second; }
    int getID() const { return ID; }
    friend bool before(const Schedule, const Schedule);
};

bool _before(const Schedule &s1, const Schedule &s2)
{
    if (s1.getYear() == s2.getYear())
    {
        if (s1.getMonth() == s2.getMonth())
        {
            if (s1.getDay() == s2.getDay())
            {
                if (s1.getHour() == s2.getHour())
                {
                    if (s1.getMinute() == s2.getMinute())
                    {
                        if (s1.getSecond() == s2.getSecond())
                        {
                            return s1.getID() < s2.getID();
                        }
                        return s1.getSecond() < s2.getSecond();
                    }
                    return s1.getMinute() < s2.getMinute();
                }
                return s1.getHour() < s2.getHour();
            }
            return s1.getDay() < s2.getDay();
        }
        return s1.getMonth() < s2.getMonth();
    }
    return s1.getYear() < s2.getYear();
}

void QAQ()
{
    while (1)
    {
        int y, m, d, h, min, s, id;
        cin >> id;
        if (!id)
            break;

        cin >> y >> m >> d >> h >> min >> s;
        Schedule sc(y, m, d, h, min, s, id);
        v.push_back(sc);
    }
    sort(v.begin(), v.end(), _before);
    cout.fill('0');
    cout << "The urgent schedule is No." << v[0].getID() << ": " << v[0].getYear() << "/" << setw(2) << v[0].getMonth() << "/" << setw(2) << v[0].getDay() << " " << setw(2) << v[0].getHour() << ":" << setw(2) << v[0].getMinute() << ":" << setw(2) << v[0].getSecond() << endl;
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
    //    cin>>t;
    while (t--)
    {
        QAQ();
    }
    return 0;
}