#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef double db;
#define int long long

class rule4
{
    string num;

public:
    rule4() { num = "0"; }
    rule4(string n) : num(n) {}
    rule4 operator+(const rule4 &rhs)
    {
        bool flag = 0;
        string ans;
        for (int i = num.size() - 1, j = rhs.num.size() - 1; i >= 0 || j >= 0; i--, j--)
        {
            int num1 = (i >= 0) ? num[i] - '0' : 0;
            int num2 = (j >= 0) ? rhs.num[j] - '0' : 0;
            ans += (num1 + num2 + flag) % 4 + '0';
            flag = (num1 + num2 + flag) / 4;
        }
        if (flag)
            ans += '1';
        reverse(ans.begin(), ans.end());
        return rule4(ans);
    }
    friend ostream &operator<<(ostream &out, const rule4 &rhs);
};

ostream &operator<<(ostream &out, const rule4 &rhs)
{
    out << rhs.num;
    return out;
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
    rule4 ans;
    while (t--)
    {
        string n;
        cin >> n;
        ans = ans + rule4(n);
    }
    cout << ans << endl;
    return 0;
}