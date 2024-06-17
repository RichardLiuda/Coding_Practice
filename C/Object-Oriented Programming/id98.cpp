#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef double db;
#define int long long

class CAccount
{
private:
    long account;
    char name[10];
    float balance;

public:
    CAccount(long acc, char *n, float bal)
    {
        account = acc;
        strcpy(name, n);
        balance = bal;
    }
    void check() { cout << name << "'s balance is " << balance << endl; }
    void deposit(float amount)
    {
        balance += amount;
        cout << "saving ok!" << endl;
    }
    void withdraw(float amount)
    {
        if (amount <= balance)
        {
            balance -= amount;
            cout << "withdraw ok!" << endl;
        }
        else
            cout << "sorry! over limit!" << endl;
    }
};

void QAQ()
{
    long account, amt;
    char name[10];
    float amount;
    cin >> account >> name >> amount;
    CAccount acc(account, name, amount);
    acc.check();
    cin >> amt;
    acc.deposit(amt);
    acc.check();
    cin >> amt;
    acc.withdraw(amt);
    acc.check();
}

signed main()
{
    //#ifndef ONLINE_JUDGE
    //    freopen("in.in", "r", stdin);
    //    freopen("out.out", "w", stdout);
    //#endif
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t = 2;
    // cin >> t;
    while (t--)
    {
        QAQ();
    }
    return 0;
}