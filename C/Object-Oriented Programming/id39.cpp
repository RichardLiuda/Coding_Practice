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
    vector<birth> bir(t);
    while (t--)
    {
        cin >> bir[t].year >> bir[t].month >> bir[t].day;
    }
    sort(bir.begin(), bir.end(), cmp);
    cout << bir[1].year << "-" << bir[1].month << "-" << bir[1].day << endl;
    return 0;
}