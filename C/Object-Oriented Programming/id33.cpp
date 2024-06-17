#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef double db;
#define int long long

int cmp(char *s1, char *s2)
{
    if (strlen(s1) > strlen(s2))
        return 1;
    else if (strlen(s1) < strlen(s2))
        return -1;
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < strlen(s1); i++)
    {
        if (*(s1 + i) > *(s2 + i))
            cnt1++;
        else if (*(s1 + i) < *(s2 + i))
            cnt2++;
    }
    if (cnt1 == cnt2)
        return 0;
    else if (cnt1 > cnt2)
        return 1;
    else
        return -1;
}

void QAQ()
{
    char *s1 = new char[N];
    char *s2 = new char[N];
    cin >> s1;
    cin >> s2;
    cout << cmp(s1, s2) << endl;
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