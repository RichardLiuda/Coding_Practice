#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef double db;
#define int long long

class Journal
{
protected:
    int id1;
    int bonus1;

public:
    Journal(int id, int bonus) : id1(id), bonus1(bonus) {}
    void __Order(float x)
    {
        bonus1 += x;
    }
    void print() { cout << id1 << ' ' << bonus1 << endl; }
};

class Credit
{
protected:
    int id2;
    string name;
    int amount;
    float bill;
    int bonus2;

public:
    Credit(int id, string name, int amount, float bill, int bonus) : id2(id), name(name), amount(amount), bill(bill), bonus2(bonus) {}
    void Consume(float x)
    {
        if (amount - bill - x >= 0)
        {
            bill += x;
            bonus2 += (int)x;
        }
    }
    void Quit(float x)
    {
        bonus2 -= (int)x;
        bill -= x;
    }
    void print() { cout << id2 << ' ' << name << ' ' << bill << ' ' << bonus2 << endl; }
};

class JournalCredit : public Journal, public Credit
{
public:
    JournalCredit(int id1, int id2, string name, int amount) : Journal(id1, 0), Credit(id2, name, amount, 0, 0) {}
    void transfer(float x)
    {
        bonus1 += (int)x / 2;
        bonus2 -= (int)x;
    }
    void Order(float x)
    {
        bonus1 += (int)x;
        bonus2 += (int)x;
        bill += x;
    }
    void print()
    {
        Journal::print();
        Credit::print();
    }
};

void QAQ()
{
    int id1, id2;
    string name;
    int amount;
    cin >> id1 >> id2 >> name >> amount;
    JournalCredit jc(id1, id2, name, amount);
    int n;
    cin >> n;
    while (n--)
    {
        char op;
        float x;
        cin >> op >> x;
        if (op == 'o')
            jc.Order(x);
        else if (op == 'c')
            jc.Consume(x);
        else if (op == 'q')
            jc.Quit(x);
        else
            jc.transfer(x);
    }
    jc.print();
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