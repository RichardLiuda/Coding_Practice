#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef double db;
#define int long long

void QAQ()
{
    char *s1 = new char[N];
    char *key0 = new char[N];
    cin >> s1;
    cin >> key0;
    int *key = new int[N];
    int cnt = 0;
    for (int i = 0; key0[i] != '\0'; i++)
    {
        key[i] = key0[i] - '0';
        cnt++;
    }
    char *s2 = new char[strlen(s1) + 1];
    char *p, *s;
    int *q;
    p = s1;
    q = key;
    s = s2;
    for (int i = 0; i < strlen(s1); i++)
    {
        *s = *p + *q;
        if (*s > 'z' || (*s > 'Z' && *s < 'a'))
            *s -= 26;
        s++;
        p++;
        q++;
        if (q - key >= cnt)
            q = key;
    }
    cout << s2 << endl;
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