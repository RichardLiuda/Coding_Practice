#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef double db;
#define int long long

char *strAdd(const char *s1, const char *s2)
{
    char *s = new char[strlen(s1) + strlen(s2) + 1]{0};
    strcat(s, s1);
    strcat(s, s2);
    return s;
}

void QAQ()
{
    char *s1 = new char[N], *s2 = new char[N];
    cin >> s1;
    cin >> s2;
    cout << s1 << " " << s2 << " " << strAdd(s1, s2) << endl;
    delete[] s1;
    delete[] s2;
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
    while (t--)
    {
        QAQ();
    }
    return 0;
}