#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef double db;
#define int long long

class Fun
{
    int n;
    vector<pair<int, int>> x;

public:
    Fun() { n = 0; }
    Fun operator+(Fun &rhs)
    {
        Fun ans;
        ans.x = x;
        for (int i = 0; i < rhs.n; i++)
        {
            bool flag = 0;
            for (int j = 0; j < n; j++)
            {
                if (rhs.x[i].second == x[j].second)
                {
                    ans.x[j].first += rhs.x[i].first;
                    if (ans.x[j].first == 0)
                        ans.x.erase(ans.x.begin() + j);
                    flag = 1;
                    break;
                }
            }
            if (!flag)
                ans.x.push_back(rhs.x[i]);
        }
        ans.n = ans.x.size();
        sort(ans.x.begin(), ans.x.end(), [](pair<int, int> a, pair<int, int> b)
             { return a.second < b.second; });
        return ans;
    }
    Fun operator-(Fun &rhs)
    {
        Fun tmprhs = rhs;
        for (int i = 0; i < rhs.n; i++)
        {
            tmprhs.x[i].first = -rhs.x[i].first;
        }
        return *this + tmprhs;
    }
    Fun operator*(Fun &rhs)
    {
        Fun ans;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < rhs.n; j++)
            {
                Fun tmp;
                tmp.x.push_back({x[i].first * rhs.x[j].first, x[i].second + rhs.x[j].second});
                tmp.n = tmp.x.size();
                ans = ans + tmp;
            }
        }
        ans.n = ans.x.size();
        sort(ans.x.begin(), ans.x.end(), [](pair<int, int> a, pair<int, int> b)
             { return a.second < b.second; });
        return ans;
    }
    friend istream &operator>>(istream &in, Fun &fun);
    friend ostream &operator<<(ostream &out, const Fun &fun);
};

istream &operator>>(istream &in, Fun &fun)
{
    in >> fun.n;
    for (int i = 0; i < fun.n; i++)
    {
        int p, k;
        cin >> p >> k;
        fun.x.push_back({p, k});
    }
    return in;
}

ostream &operator<<(ostream &out, const Fun &fun)
{
    if (fun.n == 0)
    {
        out << "0";
        return out;
    }
    for (int i = 0; i < fun.n; i++)
    {
        // out << fun.x[i].first;
        if (i)
        {
            out << (fun.x[i].first > 0 ? "+" : "");
        }
        if (fun.x[i].first == 1)
            out << (fun.x[i].second == 0 ? "1" : "");
        else if (fun.x[i].first == -1)
            out << (fun.x[i].second == 0 ? "-1" : "-");
        else
            out << fun.x[i].first;
        if (fun.x[i].second == 0)
            continue;
        else if (fun.x[i].second == 1)
            out << "x";
        else
            out << "x^" << fun.x[i].second;
    }
    return out;
}

void QAQ()
{
    Fun a, b;
    cin >> a >> b;
    cout << a + b << endl;
    cout << a - b << endl;
    cout << a * b << endl;
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