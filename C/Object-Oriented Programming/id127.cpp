#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef double db;
#define int long long

class Date
{
private:
    int year, month, day;

public:
    Date(int y, int m, int d) : year(y), month(m), day(d) {}
    void print() { cout << year << "." << month << "." << day; }
};

class Phone
{
private:
    char type;
    string telnum;
    int situ;
    Date *stop;

public:
    Phone(char t, string n, int s, Date *st) : type(t), telnum(n), situ(s), stop(st)
    {
        cout << "Construct a new phone " << telnum << endl;
        cout << "类型=" << (type == 'A' ? "机构" : (type == 'B' ? "企业" : "个人")) << "||"
             << "号码=" << telnum << "||"
             << "State=" << (situ == 1 ? "在用" : (situ == 2) ? "未用"
                                                              : "停用")
             << endl;
    }
    Phone(Phone &a) : type(a.type), telnum(a.telnum), situ(a.situ), stop(a.stop)
    {
        cout << "Construct a copy of phone " << telnum << endl;
        telnum.append("X");
        cout << "类型="
             << "备份"
             << "||"
             << "号码=" << telnum << "||"
             << "State=" << (situ == 1 ? "在用" : (situ == 2) ? "未用"
                                                              : "停用")
             << endl;
    }
    void Stop()
    {
        situ = 3;
        cout << "Stop the phone " << telnum << endl;
        cout << "类型="
             << (type == 'A' ? "机构" : (type == 'B' ? "企业" : "个人"))
             << "||"
             << "号码=" << telnum << "||"
             << "State=" << (situ == 1 ? "在用" : (situ == 2) ? "未用"
                                                              : "停用")
             << " ||"
             << "停机日期=";
        stop->print();
        cout << endl;
    }
};

void QAQ()
{
    char type;
    string telnum;
    int situ;
    int y, m, d;
    cin >> type >> telnum >> situ >> y >> m >> d;
    Date *stop = new Date(y, m, d);
    Phone a(type, telnum, situ, stop);
    Phone b(a);
    a.Stop();
    cout << "----" << endl;
    delete stop;
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