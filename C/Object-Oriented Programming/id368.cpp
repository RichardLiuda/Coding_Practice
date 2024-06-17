#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef double db;
#define int long long

class Account
{
    int balance;
    float rate;
    int id;
    char type;

public:
    Account(int id, char type, int balance)
    {
        this->id = id;
        this->type = type;
        this->balance = balance;
        rate = 0.005;
    }
    void cal()
    {
        balance += balance * rate;
        cout << "Account=" << id << "--sum=" << balance << endl;
    }
    void print()
    {
        cout << "Account=" << id << "--" << (type == 'P' ? "Person" : "Enterprise") << "--sum=" << balance << "--rate=" << rate << endl;
    }
    Account(const Account &a)
    {
        id = a.id + 50000000;
        balance = a.balance;
        rate = 0.015;
        type = a.type;
    }
};

void QAQ()
{
    int id, balance;
    char type;
    cin >> id >> type >> balance;
    Account l(id, type, balance);
    Account c(l);
    char op;
    cin >> op;
    if (op == 'C')
        l.cal();
    else
        l.print();
    cin >> op;
    if (op == 'C')
        c.cal();
    else
        c.print();
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