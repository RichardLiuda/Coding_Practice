#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef double db;
#define int long long

int total, hun, fif;

class CExaminee
{
    int no;
    int Politics, English, Math, Computer;
    int sum;

public:
    CExaminee(int n, int p, int e, int m, int c) : no(n), Politics(p), English(e), Math(m), Computer(c) { sum = p + e + m + c; }
    void isPassed()
    {
        if (sum >= total && Politics >= hun && English >= hun && Math >= fif && Computer >= fif)
            cout << no << "pass" << endl;
        else
            cout << no << "fail" << endl;
    }
};

void QAQ()
{
    int n, p, e, m, c;
    cin >> n >> p >> e >> m >> c;
    CExaminee stu(n, p, e, m, c);
    stu.isPassed();
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
    cin >> total >> hun >> fif;
    cin >> t;
    while (t--)
    {
        QAQ();
    }
    return 0;
}