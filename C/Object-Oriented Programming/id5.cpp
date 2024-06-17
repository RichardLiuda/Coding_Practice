#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef double db;
#define int long long
string op;
vector<string> a;
bool flag = 1;

string solve()
{
    cin >> op;
    if (op == "copy")
    {
        int n = stoi(solve());
        int x = stoi(solve());
        int l = stoi(solve());
        return a[n].substr(x, l);
    }
    else if (op == "add")
    {
        int s1 = stoi(solve());
        int s2 = stoi(solve());
        if (s1 >= 0 && s1 <= 99999 && s2 >= 0 && s2 <= 99999)
            return to_string(s1 + s2);
        else
            return to_string(s1) + to_string(s2);
    }
    else if (op == "find")
    {
        string s = solve();
        int n = stoi(solve());
        // cout << a[n] << " " << s << endl;
        return to_string(a[n].find(s) == string::npos ? a[n].size() : a[n].find(s));
    }
    else if (op == "rfind")
    {
        string s = solve();
        int n = stoi(solve());
        // cout << a[n] << " " << s << endl;
        return to_string(a[n].rfind(s) == string::npos ? a[n].size() : a[n].rfind(s));
    }
    else if (op == "insert")
    {
        string s = solve();
        int n = stoi(solve());
        int x = stoi(solve());
        return a[n].insert(x, s);
    }
    else if (op == "reset")
    {
        string s = solve();
        int n = stoi(solve());
        a[n] = s;
        return "0";
    }
    else if (op == "print")
    {
        int n = stoi(solve());
        cout << a[n] << endl;
        return "0";
    }
    else if (op == "printall")
    {
        for (int i = 1; i <= 3; i++)
            cout << a[i] << endl;
        return "0";
    }
    else if (op == "over")
    {
        flag = 0;
        return "0";
    }
    return op;
}

void QAQ()
{
    int n;
    cin >> n;
    a.resize(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    while (flag)
    {
        solve();
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