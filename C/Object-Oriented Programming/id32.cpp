#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef double db;
#define int long long

const string *month = new string[12]{"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

void QAQ()
{
    int n;
    cin >> n;
    if (n <= 12 && n >= 1)
        cout << *(month + n - 1) << endl;
    else
        cout << "error" << endl;
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