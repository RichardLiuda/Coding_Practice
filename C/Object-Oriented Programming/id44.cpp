#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef double db;
#define int long long

void find(int *num, int n, int &minIndex, int &maxIndex)
{
    for (int i = 0; i < n; i++)
    {
        if (num[i] < num[minIndex])
            minIndex = i;
        if (num[i] > num[maxIndex])
            maxIndex = i;
    }
}

void QAQ()
{
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int minIndex = 0, maxIndex = 0;
    find(a, n, minIndex, maxIndex);
    cout << "min=" << a[minIndex] << " "
         << "minindex=" << minIndex << endl;
    cout << "max=" << a[maxIndex] << " "
         << "maxindex=" << maxIndex << endl;
    cout << endl;
    delete[] a;
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