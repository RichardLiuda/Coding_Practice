#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef double db;
#define int long long

class CPerson
{
    string name;
    string tel;

public:
    CPerson(string name, string tel)
    {
        this->name = name;
        this->tel = tel;
    }
    string getName() { return name; }
    string getTel() { return tel; }
};

class CStudent : public CPerson
{
    vector<int> Atime;

public:
    CStudent(string name, string tel, vector<int> Atime) : CPerson(name, tel), Atime(Atime) {}
    void check()
    {
        int sum = 0;
        for (auto i : Atime)
            sum += (i >= 60 ? 1 : 0);
        if (sum >= 10)
            cout << getName() << "达到学时要求可以预约！电话" << getTel() << endl;
        else
            cout << getName() << "未达到学时要求不能预约！电话" << getTel() << endl;
    }
    vector<int> getAtime() { return Atime; }
};

class VIPStudent : public CStudent
{
    vector<int> Btime;

public:
    VIPStudent(CStudent stu, vector<int> Btime) : CStudent(stu), Btime(Btime) {}
    void check()
    {
        int sum = 0;
        for (auto i : Btime)
            sum += (i >= 120 ? 2 : i / 60);
        for (auto i : getAtime())
            sum += (i >= 180 ? 3 : i / 60);
        if (sum >= 10)
            cout << getName() << "达到学时要求可以预约！电话" << getTel() << endl;
        else
            cout << getName() << "未达到学时要求不能预约！电话" << getTel() << endl;
    }
};

void QAQ()
{
    stringstream ss;
    string s;
    cin.ignore();
    getline(cin, s);
    ss << s;
    string op, name, tel;
    ss >> op >> name >> tel;
    vector<int> Atime(12);
    for (int i = 0; i < 12; i++)
        cin >> Atime[i];
    if (op == "V")
    {
        vector<int> Btime(12);
        for (int i = 0; i < 12; i++)
            cin >> Btime[i];
        CStudent tmp(name, tel, Atime);
        VIPStudent stu(tmp, Btime);
        stu.check();
    }
    else
    {
        CStudent stu(name, tel, Atime);
        stu.check();
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