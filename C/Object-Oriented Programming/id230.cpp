#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef double db;
#define int long long

class CAccount
{
    long account;
    char name[10];
    float balance;

public:
    CAccount(long account, const char *name, float balance)
    {
        this->account = account;
        strcpy(this->name, name);
        this->balance = balance;
    }
    void deposit(float money)
    {
        balance += money;
        cout << "saving ok!" << endl;
    }
    void withdraw(float money)
    {
        if (balance >= money)
        {
            balance -= money;
            cout << "withdraw ok!" << endl;
        }
        else
        {
            cout << "sorry! over balance!" << endl;
        }
    }
    void check()
    {
        cout << "balance is " << balance << endl;
    }
    float getBalance() { return balance; }
    void setBalance(float balance) { this->balance = balance; }
};

class CCreditcard : public CAccount
{
    float limit;

public:
    CCreditcard(long account, const char *name, float balance, float limit) : CAccount(account, name, balance), limit(limit) {}
    void withdraw(float money)
    {
        if (money > getBalance() + limit)
        {
            cout << "sorry! over limit!" << endl;
        }
        else
        {
            setBalance(getBalance() - money);
            cout << "withdraw ok!" << endl;
        }
    }
};

void QAQ()
{
    long account;
    string name;
    float balance, limit;
    cin >> account >> name >> balance;
    CAccount c1(account, name.c_str(), balance);
    c1.check();
    int n;
    cin >> n;
    c1.deposit(n);
    c1.check();
    cin >> n;
    c1.withdraw(n);
    c1.check();
    cin >> account >> name >> balance >> limit;
    CCreditcard c2(account, name.c_str(), balance, limit);
    c2.check();
    cin >> n;
    c2.deposit(n);
    c2.check();
    cin >> n;
    c2.withdraw(n);
    c2.check();
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