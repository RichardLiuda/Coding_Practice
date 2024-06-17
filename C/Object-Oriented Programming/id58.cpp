#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef double db;
#define int long long

struct student
{
    string id;
    string name;
    int mark1, mark2, mark3;
    int tol;
};

bool cmp(student &a, student &b)
{
    return a.tol > b.tol;
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
    vector<student> stu(t);
    t--;
    while (t--)
    {
        cin >> stu[t].id >> stu[t].name >> stu[t].mark1 >> stu[t].mark2 >> stu[t].mark3;
        stu[t].tol = stu[t].mark1 + stu[t].mark2 + stu[t].mark3;
    }
    sort(stu.begin(), stu.end(), cmp);
    cout << stu[0].name << " " << stu[0].id << " " << stu[0].tol << endl;
    return 0;
}