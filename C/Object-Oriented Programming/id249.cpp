#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef double db;
#define int long long

class Crew
{
protected:
    string name, pos;
    int lev, year;

public:
    Crew(string name, string pos, int lev, int year)
    {
        this->name = name;
        this->pos = pos;
        this->lev = lev;
        this->year = year;
    }
    virtual double salary() = 0;
    virtual void print() = 0; // 输出信息
};

class Employee : public Crew
{
public:
    Employee(string name, string pos, int lev, int year) : Crew(name, pos, lev, year) {}
    double salary()
    {
        return 1000 + 500 * lev + 50 * year;
    }
    void print()
    {
        cout << name << ":" << pos << ",Salary:" << salary() << endl;
    }
};
class TeamLeader : public Crew
{
public:
    TeamLeader(string name, string pos, int lev, int year) : Crew(name, pos, lev, year) {}
    double salary()
    {
        return 3000 + 800 * lev + 100 * year;
    }
    void print()
    {
        cout << name << ":" << pos << ",Salary:" << salary() << endl;
    }
};
class Manager : public Crew
{
public:
    Manager(string name, string pos, int lev, int year) : Crew(name, pos, lev, year) {}
    double salary()
    {
        return 5000 + 1000 * lev + 1000 * year;
    }
    void print()
    {
        cout << name << ":" << pos << ",Salary:" << salary() << endl;
    }
};

void QAQ()
{
    string n, p;
    int l, y;
    cin >> n >> p >> l >> y;
    Crew *pc;
    if (p != "Employee" && p != "Teamleader" && p != "Manager")
    {
        cout << "error position." << endl;
        return;
    }
    if (y < 0 || l < 0)
    {
        cout << "error grade or year." << endl;
        return;
    }
    if (p == "Employee")
    {
        Employee a(n, p, l, y);
        pc = &a;
        pc->print();
    }
    else if (p == "Teamleader")
    {
        TeamLeader a(n, p, l, y);
        pc = &a;
        pc->print();
    }
    else if (p == "Manager")
    {
        Manager a(n, p, l, y);
        pc = &a;
        pc->print();
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
    cin >> t;
    while (t--)
    {
        QAQ();
    }
    return 0;
}