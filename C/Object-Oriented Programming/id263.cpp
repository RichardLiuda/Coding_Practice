#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef double db;
#define int long long

class Group
{
public:
    virtual int add(int x, int y) = 0; // 输出加法的运算结果
    virtual int sub(int x, int y) = 0; // 输出减法的运算结果
};

class GroupA : public Group
{
public:
    int add(int x, int y) { return x + y; }
    int sub(int x, int y) { return x - y; }
};

class GroupB : public Group
{
public:
    int add(int x, int y) { return x + y; }
    int sub(int x, int y)
    {
        int ans = 0;
        string sx = to_string(x);
        string sy = to_string(y);
        while (sx.size() != sy.size())
        {
            sy = "0" + sy;
        }
        for (int i = 0; i < sx.size(); i++)
        {
            ans *= 10;
            ans += ((sx[i] - '0') + 10 - (sy[i] - '0')) % 10;
        }
        return ans;
    }
};

class GroupC : public Group
{
public:
    int sub(int x, int y)
    {
        int ans = 0;
        string sx = to_string(x);
        string sy = to_string(y);
        while (sx.size() != sy.size())
        {
            sy = "0" + sy;
        }
        for (int i = 0; i < sx.size(); i++)
        {
            ans *= 10;
            ans += ((sx[i] - '0') + 10 - (sy[i] - '0')) % 10;
        }
        return ans;
    }
    int add(int x, int y)
    {
        int ans = 0;
        string sx = to_string(x);
        string sy = to_string(y);
        while (sx.size() > sy.size())
        {
            sy = "0" + sy;
        }
        while (sx.size() < sy.size())
        {
            sx = "0" + sx;
        }
        for (int i = 0; i < sx.size(); i++)
        {
            ans *= 10;
            ans += ((sx[i] - '0') + (sy[i] - '0')) % 10;
        }
        return ans;
    }
};

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
    Group *p;
    while (t--)
    {
        int type;
        cin >> type;
        int x, y;
        char c;
        cin >> x >> c >> y;
        if (type == 1)
        {
            GroupA a;
            p = &a;
            if (c == '+')
                cout << p->add(x, y) << endl;
            else
                cout << p->sub(x, y) << endl;
        }
        else if (type == 2)
        {
            GroupB a;
            p = &a;
            if (c == '+')
                cout << p->add(x, y) << endl;
            else
                cout << p->sub(x, y) << endl;
        }
        else
        {
            GroupC a;
            p = &a;
            if (c == '+')
                cout << p->add(x, y) << endl;
            else
                cout << p->sub(x, y) << endl;
        }
    }
    return 0;
}