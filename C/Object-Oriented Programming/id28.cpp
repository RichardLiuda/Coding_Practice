#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef double db;
#define int long long

struct SPoint
{
    int x, y;
};

struct SRect
{
    SPoint p1, p2;
};

bool isoverlap(const SRect &rect1, const SRect &rect2)
{
    return (max(rect1.p1.x, rect2.p1.x) > min(rect1.p2.x, rect2.p2.x) ||
            max(rect1.p1.y, rect2.p1.y) > min(rect1.p2.y, rect2.p2.y));
}

void QAQ()
{
    SRect sq1, sq2;
    cin >> sq1.p1.x >> sq1.p1.y >> sq1.p2.x >> sq1.p2.y;
    cin >> sq2.p1.x >> sq2.p1.y >> sq2.p2.x >> sq2.p2.y;
    if (sq1.p1.x > sq1.p2.x)
        swap(sq1.p1.x, sq1.p2.x);
    if (sq2.p1.x > sq2.p2.x)
        swap(sq2.p1.x, sq2.p2.x);
    if (sq1.p1.y > sq1.p2.y)
        swap(sq1.p1.y, sq1.p2.y);
    if (sq2.p1.y > sq2.p2.y)
        swap(sq2.p1.y, sq2.p2.y);
    if (isoverlap(sq1, sq2))
        cout << "not overlapped" << endl;
    else
        cout << "overlapped" << endl;
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