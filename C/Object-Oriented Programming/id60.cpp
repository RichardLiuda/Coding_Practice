#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef double db;
#define int long long

struct birth
{
    int year, month, day;
};

bool cmp(birth &a, birth &b)
{
    if (a.year != b.year)
        return a.year < b.year;
    if (a.month != b.month)
        return a.month < b.month;
    return a.day < b.day;
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
    vector<birth> a;
    for (int i = 1; i <= t; i++)
    {
        birth tmp;
        cin >> tmp.year >> tmp.month >> tmp.day;
        a.push_back(tmp);
    }
    sort(a.begin(), a.end(), cmp);
    int cnt = 0;
    for (auto i : a)
        cout << ++cnt << ":" << i.year << "-" << i.month << "-" << i.day << endl;
    return 0;
}