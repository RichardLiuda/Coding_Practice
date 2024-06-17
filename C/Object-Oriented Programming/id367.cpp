#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef double db;
#define int long long

class Telnum
{
private:
    int num;
    char type;

public:
    Telnum(int num, char type)
    {
        this->num = num;
        this->type = type;
        cout << num << " constructed." << endl;
    }
    void show()
    {
        cout << "Phone=" << num << "--Type=" << type;
    }
    bool check(int num) { return this->num == num; }
    ~Telnum() { cout << num << " destructed." << endl; }
};

class Tel
{
private:
    Telnum tn;
    int status;
    string name;

public:
    Tel(int num, char type, int status, string name) : tn(Telnum(num, type)), status(status), name(name) {}
    ~Tel() {}
    bool check(int num) { return tn.check(num); }
    void show()
    {
        tn.show();
        cout << "--State=" << (status ? "use" : "unuse") << "--Owner=" << name << endl;
    }
};

void QAQ()
{
    // int t = 3;
    // vector<Tel> tel;
    // while (t--)
    // {
    //     int num, status;
    //     string name;
    //     char type;
    //     cin >> num >> type >> status >> name;
    //     tel.push_back(Tel(num, type, status, name));
    // }
    int num, status;
    string name;
    char type;
    cin >> num >> type >> status >> name;
    Tel t1(num, type, status, name);
    cin >> num >> type >> status >> name;
    Tel t2(num, type, status, name);
    cin >> num >> type >> status >> name;
    Tel t3(num, type, status, name);
    int t;
    cin >> t;
    while (t--)
    {
        int _num;
        cin >> _num;
        bool flag = 0;
        if (t1.check(_num))
        {
            t1.show();
            flag = 1;
        }
        if (t2.check(_num))
        {
            t2.show();
            flag = 1;
        }
        if (t3.check(_num))
        {
            t3.show();
            flag = 1;
        }
        if (!flag)
            cout << "wrong number." << endl;

        // for (auto it : tel)
        // {
        //     if (it.check(_num))
        //     {
        //         it.show();
        //         flag = 1;
        //         break;
        //     }
        // }
        // if (!flag)
        //     cout << "wrong number." << endl;
        // auto it = find(tel.begin(), tel.end(), [&](Tel t)
        //                { return t.check(_num); });
        // if (it == tel.end())
        //     cout << "wrong number." << endl;
        // else
        //     it->show();
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
    //    cin>>t;
    while (t--)
    {
        QAQ();
    }
    return 0;
}