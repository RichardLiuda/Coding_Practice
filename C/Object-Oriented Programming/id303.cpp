#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef double db;
#define int long long

class Student
{
    string name;
    int year, month, day;

public:
    Student() {}
    Student(string name, int year, int month, int day) : name(name), year(year), month(month), day(day) {}
    void swap(Student &rhs)
    {
        int tmp = rhs.year;
        rhs.year = this->year;
        this->year = tmp;
        tmp = rhs.month;
        rhs.month = this->month;
        this->month = tmp;
        tmp = rhs.day;
        rhs.day = this->day;
        this->day = tmp;
        string tmp2 = rhs.name;
        rhs.name = this->name;
        this->name = tmp2;
    }
    int operator-(Student &rhs)
    {
        bool flag = 0;
        if (rhs.year < this->year)
        {
            flag = 1;
            swap(rhs);
        }
        else if (rhs.year == this->year)
        {
            if (rhs.month < this->month)
            {
                flag = 1;
                swap(rhs);
            }
            if (rhs.month == this->month)
            {
                if (rhs.day < this->day)
                {
                    flag = 1;
                    swap(rhs);
                }
            }
        }
        int days = 0;
        int months[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        for (int i = this->year; i < rhs.year; i++)
        {
            days += (i % 400 == 0 || (i % 4 == 0 && i % 100 != 0)) ? 366 : 365;
        }
        for (int i = 1; i < rhs.month; i++)
        {
            days += months[i];
            if ((rhs.year % 4 == 0 && rhs.year % 100 != 0 || rhs.year % 400 == 0) && i == 2)
                days++;
        }
        days += rhs.day;
        for (int i = 1; i < this->month; i++)
        {
            days -= months[i];
            if ((rhs.year % 4 == 0 && this->year % 100 != 0 || this->year % 400 == 0) && i == 2)
                days--;
        }
        days -= this->day;
        return flag ? -days : days;
    }
    string getName()
    {
        return name;
    }
};

void QAQ()
{
    int n;
    cin >> n;
    vector<Student> s;
    for (int i = 0; i < n; i++)
    {
        string name;
        int year, month, day;
        cin >> name >> year >> month >> day;
        s.push_back(Student(name, year, month, day));
    }
    string n1, n2;
    int maxx = 0;
    for (auto i : s)
    {
        for (auto j : s)
        {
            // cout << i.getName() << "-" << j.getName() << " " << i - j << endl;
            if (i - j > maxx)
            {
                maxx = i - j;
                n1 = i.getName();
                n2 = j.getName();
            }
        }
    }
    cout << n1 << "和" << n2 << "年龄相差最大，为" << maxx << "天。" << endl;
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