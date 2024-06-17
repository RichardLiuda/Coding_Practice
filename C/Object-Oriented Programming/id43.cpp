#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef double db;
#define int long long

// struct date
// {
//     int mon, day;
// };

// struct times
// {
//     int year, mon, day;
// };

struct rece
{
    string tmnid, optr;
    string sdr;
    string date;
    string id;
    string time;
    string money;
};

void QAQ()
{
    string name;
    getline(cin, name, ' ');
    if (name[0] == '\n')
        name.erase(0, 1);
    rece r;
    getline(cin, r.tmnid, ' ');
    getline(cin, r.optr, ' ');
    getline(cin, r.sdr, ' ');
    getline(cin, r.date, ' ');
    getline(cin, r.id, ' ');
    getline(cin, r.time, ' ');
    getline(cin, r.money, '\n');
    cout << "Name: " << name << endl;
    cout << "Terminal: " << r.tmnid << " operator: " << r.optr << endl;
    cout << "Card Issuers: " << r.sdr << " Validity: " << r.date << endl;
    string s1, s2;
    s1 = r.id.substr(0, 4);
    s2 = r.id.substr(12, 15);
    cout << "CardNumber: " << s1 << "********" << s2 << endl;
    cout << "Traded: " << r.time << endl;
    cout << "Costs: $" << r.money << endl;
    cout << endl;
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