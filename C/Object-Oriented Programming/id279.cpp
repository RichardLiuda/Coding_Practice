#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef double db;
#define int long long

class CVehicle
{
private:
    int max_speed, speed, weight;

public:
    CVehicle() {}
    CVehicle(int max_speed, int speed, int weight)
    {
        this->max_speed = max_speed;
        this->speed = speed;
        this->weight = weight;
    }
    void display()
    {
        cout << "max_speed:" << max_speed << endl;
        cout << "speed:" << speed << endl;
        cout << "weight:" << weight << endl;
    }
    ~CVehicle() {}
};

class CBicycle : virtual public CVehicle
{
private:
    int height;

public:
    CBicycle(int max_speed, int speed, int weight, int height) : CVehicle(max_speed, speed, weight)
    {
        this->height = height;
    }
    CBicycle(int height)
    {
        this->height = height;
    }
    void display()
    {
        CVehicle::display();
        cout << "height:" << height << endl;
    }
    ~CBicycle() {}
};

class CMotocar : virtual public CVehicle
{
private:
    int seat_num;

public:
    CMotocar(int max_speed, int speed, int weight, int seat_num) : CVehicle(max_speed, speed, weight)
    {
        this->seat_num = seat_num;
    }
    CMotocar(int seat_num)
    {
        this->seat_num = seat_num;
    }
    void display()
    {
        CVehicle::display();
        cout << "seat_num:" << seat_num << endl;
    }
    void _display()
    {
        cout << "seat_num:" << seat_num << endl;
    }
    ~CMotocar() {}
};

class CMotocycle : public CBicycle, public CMotocar
{
public:
    CMotocycle(int max_speed, int speed, int weight, int height, int seat_num) : CVehicle(max_speed, speed, weight), CBicycle(height), CMotocar(seat_num) {}
    void display()
    {
        CBicycle::display();
        CMotocar::_display();
    }
    ~CMotocycle() {}
};

void QAQ()
{
    int mxs, s, w, h, se;
    cin >> mxs >> s >> w >> h >> se;
    CVehicle c1(mxs, s, w);
    cout << "Vehicle:" << endl;
    c1.display();
    cout << endl;
    CBicycle c2(mxs, s, w, h);
    cout << "Bicycle:" << endl;
    c2.display();
    cout << endl;
    CMotocar c3(mxs, s, w, se);
    cout << "Motocar:" << endl;
    c3.display();
    cout << endl;
    CMotocycle c4(mxs, s, w, h, se);
    cout << "Motocycle:" << endl;
    c4.display();
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
    //    cin>>t;
    while (t--)
    {
        QAQ();
    }
    return 0;
}