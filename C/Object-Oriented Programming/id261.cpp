#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef double db;
#define int long long

class Vehicle
{
protected:
    string no; // 编号
public:
    Vehicle(string no) : no(no) {}
    virtual void display() = 0; // 应收费用
};

class Car : public Vehicle
{
    int num, weight;

public:
    Car(string no, int n, int w) : Vehicle(no), num(n), weight(w) {}
    void display() { cout << no << " " << 8 * num + 2 * weight << endl; } // 应收费用
};

class Truck : public Vehicle
{
    int weight;

public:
    Truck(string no, int w) : Vehicle(no), weight(w) {}
    void display() { cout << no << " " << 5 * weight << endl; } // 应收费用
};

class Bus : public Vehicle
{
    int num;

public:
    Bus(string no, int n) : Vehicle(no), num(n) {}
    void display() { cout << no << " " << 3 * num << endl; } // 应收费用
};

void QAQ()
{
    int type, num, w;
    string no;
    Vehicle *pv;
    cin >> type;
    if (type == 1)
    {
        cin >> no >> num >> w;
        Car tmp(no, num, w);
        pv = &tmp;
        pv->display();
    }
    else if (type == 2)
    {
        cin >> no >> w;
        Truck tmp(no, w);
        pv = &tmp;
        pv->display();
    }
    else if (type == 3)
    {
        cin >> no >> num;
        Bus tmp(no, num);
        pv = &tmp;
        pv->display();
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