#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef double db;
#define int long long

struct acm
{
    int id, m, rank;
};

bool cmp(acm &a, acm &b)
{
    if (a.m != b.m)
        return a.m > b.m;
    return a.rank < b.rank;
}

signed main()
{
    //#ifndef ONLINE_JUDGE
    //    freopen("in.in", "r", stdin);
    //    freopen("out.out", "w", stdout);
    //#endif
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    vector<acm> a;
    int cnt = 0;
    while (t--)
    {
        acm tmp;
        cin >> tmp.id >> tmp.m;
        tmp.rank = ++cnt;
        a.push_back(tmp);
    }
    sort(a.begin(), a.end(), cmp);
    for (auto i : a)
        cout << i.id << " " << i.m << endl;
    return 0;
}