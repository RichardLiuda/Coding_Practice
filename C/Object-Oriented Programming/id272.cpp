#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef double db;
#define int long long

class Vehicle
{
    int weight;

public:
    Vehicle() {}
    Vehicle(int w)
    {
        weight = w;
        cout << "载入Vehicle类构造函数" << endl;
    }
    void setWeight(int w)
    {
        weight = w;
        cout << "重新设置重量" << endl;
    }
    void display()
    {
        cout << "重量：" << weight << "吨，";
    }
};

class Car : virtual public Vehicle
{
    int aird;

public:
    Car(int a) : aird(a)
    {
        cout << "载入Car类构造函数" << endl;
    }
    void setAird(int a)
    {
        cout << "重新设置空气排量" << endl;
        aird = a;
    }
    void display()
    {
        cout << "空气排量：" << aird << "CC，";
    }
};

class Boat : virtual public Vehicle
{
    float tonnage;

public:
    Boat(float t) : tonnage(t)
    {
        cout << "载入Boat类构造函数" << endl;
    }
    void setTonnage(float t)
    {
        cout << "重新设置排水量" << endl;
        tonnage = t;
    }
    void display()
    {
        cout << "排水量：" << tonnage << "吨" << endl;
    }
};

class AmphibianCar : public Car, public Boat
{
public:
    AmphibianCar(int w, int a, float t) : Vehicle(w), Car(a), Boat(t)
    {
        cout << "载入AmphibianCar类构造函数" << endl;
    }
    void display()
    {
        Vehicle::display();
        Car::display();
        Boat::display();
    }
    void change(int w, int a, float t)
    {
        // cout << "重新设置重量\n重新设置空气排量\n重新设置排水量" << endl;
        setWeight(w);
        setAird(a);
        setTonnage(t);
    }
};

void QAQ()
{
    int w, a;
    float t;
    cin >> w >> a >> t;
    AmphibianCar aa(w, a, t);
    aa.display();
    cin >> w >> a >> t;
    aa.change(w, a, t);
    aa.display();
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