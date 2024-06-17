#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef double db;
#define int long long

class BaseAccount
{
protected:
    string name, account;
    int balance;

public:
    BaseAccount(string name, string account, int balance)
    {
        this->name = name;
        this->account = account;
        this->balance = balance;
    }
    virtual void deposit(int amount)
    {
        balance += amount;
    }
    virtual void withdraw(int amount)
    {
        if (amount > balance)
            cout << "insufficient" << endl;
        else
            balance -= amount;
    }
    virtual void display()
    {
        cout << name << " " << account << " Balance:" << balance << endl;
    }
};

class BasePlus : public BaseAccount
{
    int limit, limit_sum;

public:
    BasePlus(string name, string account, int balance) : BaseAccount(name, account, balance), limit(5000), limit_sum(0) {}
    void deposit(int amount)
    {
        if (limit_sum)
        {
            if (amount <= limit_sum)
                limit_sum -= amount;
            else
            {
                balance += amount - limit_sum;
                limit_sum = 0;
            }
        }
        else
            balance += amount;
    }
    void withdraw(int amount)
    {
        if (amount - balance + limit_sum > limit)
            cout << "insufficient" << endl;
        else if (amount > balance)
        {
            limit_sum += amount - balance;
            balance = 0;
        }
        else
            balance -= amount;
    }
    void display()
    {
        cout << name << " " << account << " Balance:" << balance << " limit:" << limit - limit_sum << endl;
    }
};

void QAQ()
{
    string name, account;
    int balance;
    cin >> name >> account >> balance;
    BaseAccount *p;
    if (account[1] == 'A')
    {
        p = new BaseAccount(name, account, balance);
    }
    else
    {
        p = new BasePlus(name, account, balance);
    }
    int amount;
    cin >> amount;
    p->deposit(amount);
    cin >> amount;
    p->withdraw(amount);
    cin >> amount;
    p->deposit(amount);
    cin >> amount;
    p->withdraw(amount);
    p->display();
    delete p;
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