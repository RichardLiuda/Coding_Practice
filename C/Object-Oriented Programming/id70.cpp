#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef double db;
#define int long long

void QAQ()
{
    int *matrix = new int[6];
    for (int i = 0; i < 6; i++)
        cin >> matrix[i];
    for (int i = 2;;)
    {
        cout << *(matrix + i) << " " << *(matrix + i + 3) << " " << endl;
        if (!i)
            break;
        i--;
    }
    delete[] matrix;
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