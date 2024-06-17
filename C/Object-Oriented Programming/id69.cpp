#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef double db;
#define int long long

void QAQ()
{
    char *s1 = new char[11], *s2 = new char[11], *s3 = new char[11];
    cin >> s1 >> s2 >> s3;
    int in1, in2, in3, out1, out2, out3;
    cin >> in1 >> out1 >> in2 >> out2 >> in3 >> out3;
    int len = out1 - in1 + 1 + out2 - in2 + 1 + out3 - in3 + 1;
    char *s = new char[len];
    int cnt = 0;
    for (int i = in1 - 1; i < out1; i++)
        *(s + cnt++) = *(s1 + i);
    for (int i = in2 - 1; i < out2; i++)
        *(s + cnt++) = *(s2 + i);
    for (int i = in3 - 1; i < out3; i++)
        *(s + cnt++) = *(s3 + i);
    *(s + cnt) = '\0';
    cout << s << endl;
    delete[] s, s1, s2, s3;
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