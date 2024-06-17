#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef double db;
#define int long long

class CUser
{
private:
    string name;
    int num;
    static string jiucai;
    static int count;

public:
    CUser(string name, int num) : name(name), num(num)
    {
        count += num / 2500;
    }
    int getNum() { return num; }
    string getName() { return name; }
    static int getCount() { return count; }
    static void zero() { count = 0; }
};

bool cmp(CUser &a, CUser &b) { return a.getNum() >= b.getNum(); }

int CUser::count = 0;

void QAQ()
{
    int n;
    cin >> n;
    vector<CUser> v;
    for (int i = 0; i < n; i++)
    {
        string name;
        int num;
        cin >> name >> num;
        v.push_back(CUser(name, num));
    }
    sort(v.begin(), v.end(), cmp);
    cout << "The most attentive user :" << v[0].getName() << ","
         << "and he/she has " << v[0].getNum() << " gold coins." << endl;
    cout << "There are " << CUser::getCount() << " more trees in the world!" << endl;
    CUser::zero();
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