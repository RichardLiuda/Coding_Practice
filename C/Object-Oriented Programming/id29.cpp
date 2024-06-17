#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef double db;
#define int long long

void search(int *num, int n, int *nmax, int *nmaxindex)
{
    nmax = num;
    for (int i = 1; i < n; i++)
    {
        if (num[i] > *nmax)
        {
            nmax = num + i;
            *nmaxindex = i;
        }
    }
    cout << *nmax << " " << *nmaxindex << endl;
}

void input(int *num, int n)
{
    for (int i = 0; i < n; i++)
        cin >> num[i];
}

void QAQ()
{
    int n;
    cin >> n;
    int *num = new int[n];
    int *nmax = new int, *nmaxindex = new int;
    input(num, n);
    search(num, n, nmax, nmaxindex);
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