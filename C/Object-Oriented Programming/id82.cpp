#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef double db;
#define int long long
struct dist
{
    double dis;
    int from, to;
};
vector<dist> dis;

bool cmp(dist &a, dist &b)
{
    return a.dis > b.dis;
}

class Point
{
private:
    double x, y;

public:
    Point()
    {
        x = 0;
        y = 0;
        cout << "Constructor." << endl;
    };
    Point(double x, double y)
    {
        this->x = x;
        this->y = y;
        cout << "Constructor." << endl;
    }
    double getX() { return x; }
    double getY() { return y; }
    void setXY(double x, double y)
    {
        this->x = x;
        this->y = y;
    }
    void setX(double x) { this->x = x; }
    void setY(double y) { this->y = y; }
    double getDisTo(Point &p)
    {
        return sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y));
    }
    void add(Point &p, int i, int j)
    {
        dis.push_back({getDisTo(p), i, j});
    }
    ~Point() { cout << "Distructor." << endl; }
};

void QAQ()
{
    int n;
    cin >> n;
    vector<Point> p(n);
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        p[i].setXY(x, y);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            p[i].add(p[j], i, j);
        }
    }
    sort(dis.begin(), dis.end(), cmp);
    cout << "The longeset distance is " << fixed << setprecision(2) << dis[0].dis << ",between p[" << dis[0].from << "] and p[" << dis[0].to << "]." << endl;
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
    cin >> t;
    while (t--)
    {
        QAQ();
    }
    return 0;
}